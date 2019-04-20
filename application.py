import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    
    headers = ["Symbol", "Name", "Shares", "Current Price", "TOTAL"]
    stocks = db.execute("SELECT symbol,  SUM(quantity) FROM \
                              transactions WHERE user_id = :u GROUP BY symbol", u=session["user_id"])
    grand_total = 0
    for stock in stocks:
        looked_up = lookup(stock["symbol"])
        stock.update({"company": looked_up["name"]})
        stock.update({"current_price": looked_up["price"]})
        stock.update({"total_value": stock["current_price"]*stock["SUM(quantity)"]})
        grand_total += stock["total_value"]
 
    cash = db.execute("SELECT cash FROM users WHERE id = :u", u=session["user_id"])
    cash_dict = cash[0]
    cash_value = cash_dict["cash"]
    grand_total += cash_value
    
    return render_template("index.html", cash=cash_value, grand_total=round(grand_total, 2), stocks=stocks, headers=headers)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    
    if request.method == "POST":
        
        # get stock symbol
        symbol = request.form.get("symbol")
        
        if not symbol:
            return apology("Symbol required")
        
        # look up the current stock price
        to_buy = lookup(symbol)
        
        if not to_buy:
            return apology("Invalid symbol")
        
        # get number of shares
        shares = int(request.form.get("shares"))
        
        if not shares.isdigit():
            return apology("Enter valid number of shares")
        
        user_id = session["user_id"]
        
        # check that user has enough money to buy given stocks
        cash = db.execute("SELECT cash FROM users WHERE id = :u", u=session["user_id"])
        cash_dict = cash[0]
        cash_value = cash_dict["cash"]
        price = to_buy["price"]
        
        if shares*price > cash_value:
            return apology("Insufficient Funds")
        
        # enter transaction into transactions database
        db.execute("INSERT INTO transactions (user_id, symbol, price, quantity) \
                    VALUES (:u, :s, :p, :q)", u=user_id, s=symbol, p=to_buy["price"], q=shares)  
        
        db.execute("UPDATE users SET cash = cash - :q*:p WHERE id = :u ", u=user_id, p=to_buy["price"], q=shares)
        
        flash("Bought!")
        return redirect("/")
    else:
        return render_template("buy.html")
    

@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    
    # Look up username in database
    status = db.execute("SELECT * FROM users WHERE username = :name", name=request.args.get("username"))
    
    # If username returned, return false, since username is not available
    if len(status) > 0:
        return jsonify(False)
        
    # If username is not taken, return true
    else:
        return jsonify(True)


@app.route("/history", methods=["GET"])
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT symbol, price, quantity, date_and_time FROM \
                              transactions WHERE user_id = :u", u=session["user_id"])
    headers = ["Symbol", "Price", "Shares", "Date and Time"]
    
    return render_template("history.html", transactions=transactions, headers=headers)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    
    if request.method == "POST":
        symbol = request.form.get("symbol")
        
        if not symbol:
            return apology("Valid symbol required")
        info = lookup(symbol)
        
        # check that symbol exists
        if info:
            price = info["price"]
            company = info["name"]
            
            # return current price
            return render_template("quoted.html", symbol=symbol, company=company, price=price)
        else:
            return apology("Nonexistant stock symbol")
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("Username required")
            
        # Look up username in database
        status = db.execute("SELECT * FROM users WHERE username = :name", name=request.args.get("username"))
        
        # If username returned, return false, since username is not available
        if len(status) > 0:
            return apology("Username taken")

        # Get password from form
        password = request.form.get("password")
        
        # Check that password has been entered
        if len(password) > 0:
            
            # check whether confirmation is the same as the original
            confirmation = request.form.get("confirmation")
            if password != confirmation:
                return apology("Passwords do not match")
            
            # hash the password (method, salt length poached from werkzeug example)
            password_hash = generate_password_hash(request.form.get("password"), 
                                                   method='pbkdf2:sha256', salt_length=8)
            
            # store username, password hash in database                                       
            db.execute("INSERT INTO users (username, hash) VALUES (:u, :p)", 
                       u=request.form.get("username"), p=password_hash)
            
            # notify the user that they've been properly registered
            flash("Registered!")
            return redirect("/")
        else: 
            return apology("Please enter a password")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    
    if request.method == "POST":
        
        # get stock symbol
        symbol = request.form.get("symbol")
        
        # look up the current stock price
        to_sell = lookup(symbol)
        
        # get number of shares
        shares = -1*int(request.form.get("shares"))
        
        # get current user
        user_id = session["user_id"]
        
        # check that user has enough shares to make sale
        stock = db.execute("SELECT symbol,  SUM(quantity) FROM \
                            transactions WHERE user_id = :u AND symbol= :s GROUP BY symbol", u=session["user_id"], s=symbol)
        stock_dict = stock[0]
        stock_quantity = stock_dict["SUM(quantity)"]
                            
        if abs(shares) > stock_quantity:
            return apology("Insufficient shares")
        
        # enter transaction into transactions database
        db.execute("INSERT INTO transactions (user_id, symbol, price, quantity) \
                    VALUES (:u, :s, :p, :q)", u=user_id, s=symbol, p=to_sell["price"], q=shares)  
                    
        db.execute("UPDATE users SET cash = cash - :q*:p WHERE id = :u ", u=user_id,
                   p=to_sell["price"], q=shares)
        
        flash("Sold!")
        return redirect("/")
        
    else:
        return render_template("sell.html")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
