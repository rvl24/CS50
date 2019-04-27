# Proposal

## What will (likely) be the title of your project?

Mealify would be the obvious choice. 

## In just a sentence or two, summarize your project. (E.g., "A website that lets you buy and sell stocks.")

A website which contains recipes which can be combined into a meal. Once you've chosen all the dishes you want to cook, the website will provide a single meal recipe, which has ingredients, instructions, and timing figured so that you can prepare the whole meal comprehensively. 

## In a paragraph or more, detail your project. What will your software do? What features will it have? How will it be executed?

This will be a pretty straigtforward Flask website. Users will be able to create an account, login, and save favorite recipes and favorite "meals"--combinations 
of recipes. User information and recipes will be stored in a SQLite database. The table storing recipes will need to contain information about how long each step of the 
instructions will take, so that steps can be combined for a total recipe prep time. 

## If planning to combine CS50's final project with another course's final project, with which other course? And which aspect(s) of your proposed project would relate to CS50, and which aspect(s) would relate to the other course?

TODO, if applicable

## In the world of software, most everything takes longer to implement than you expect. And so it's not uncommon to accomplish less in a fixed amount of time than you hope.

### In a sentence (or list of features), define a GOOD outcome for your final project. I.e., what WILL you accomplish no matter what?

At the most basic, the project will be a basic website which allows users to create an account and choose between a few recipes to combine into a meal recipe, 
which provides a combined list of ingredients and a prep time for the whole meal. 

### In a sentence (or list of features), define a BETTER outcome for your final project. I.e., what do you THINK you can accomplish before the final project's deadline?

The website is attractive-looking, there are a variety of recipes to choose from, and there are some extra features--like multiple options for sorting meal 
ingredients (by dish? by grocery store aisle?), ability to either print a shopping list or maybe export it to a Google Keep checklist or something 
like that. 

### In a sentence (or list of features), define a BEST outcome for your final project. I.e., what do you HOPE to accomplish before the final project's deadline?

The really cool thing would be to be able to import recipes from other sites. Perhaps through a browser extension? This seems challenging, especially because, in order to be combined into
a single meal recipe, the time for individual steps needs to be known, and that's often not included in recipes. I wonder if there is a simplified solution to this problem. 

## In a paragraph or more, outline your next steps. What new skills will you need to acquire? What topics will you need to research? If working with one of two classmates, who will do what?

I definitely did not fully grasp a lot of the concepts presented in Finance, so I need to go back through that and figure out how login/account creation works, among other details. 
I need to ponder exactly what a meal recipe looks like, and what it needs to include. I think the hardest part is going to be figuring out what information individual
recipes need to have in order to be able to combine them effectively. How can the program determine which steps can happen simultaneuosly, for instance? If I want to make a 
way to import recipes from external sites, how will that possibly work?? I think there are sites that have some of these features, although I've never 
seen a site that can combine recipe instructions and prep times. I want to see what's out there to a) make sure my idea doesn't already exist and b) get
inspiration for what features to include. 
