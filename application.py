import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    with open("survey.csv", "a", newline="") as csv_file:
        well_info = [request.form.get("well_id"),
                     request.form.get("road_box"), request.form.get("depth_to_water"),
                     request.form.get("depth_to_bottom"), request.form.get("well_condition")]
        writer = csv.writer(csv_file)
        writer.writerow(well_info)
    return get_sheet()
    
    
@app.route("/sheet", methods=["GET"])
def get_sheet():
    headers = ["Well ID", "Road Box", "Depth to Water", "Depth to Bottom", "Well Condition"]
    with open("survey.csv", "r", newline="") as csv_file:
        reader = csv.reader(csv_file)
        rows = []
        for line in reader: 
            rows.append(line)
    return render_template("sheet.html", headers=headers, rows=rows)
