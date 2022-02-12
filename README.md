# 2022 Rapid React Robot Code

This repository serves as the home for the robot code for our 2022 Rapid React robot.

This document works as a guide to developing code for our robot.

## Using Git

Git is an important tool for a few reasons when it comes to development.

1. **Storage** - GitHub works as a great storage method for our code.
2. **Backups (Version Control)** - Git allows up to quickly revert our code and look at it's various states from the past.
3. **Social Coding** - Git allows us all to work on the same codebase and quickly sync changes with other developers.

Know that you know why we use Git let's get into how to *actually* use it.

### Downloading the Files (Cloning the Repo)

Let's get the robot code on your machine for local development.

#### Command Line

```bash
git clone https://github.com/BlueCrewRobotics/2022-RapidReact.git
```

#### GitHub Desktop

Go to `File -> Clone Repository`, choose a repository to clone, and press `Clone`.

![Clone Guide One](/images/github-desktop-clone-one.png)

![Clone Guide Two](/images/github-desktop-clone-two.png)

### Setting Your Default Branch

When developing for the Blue Crew we *require* that all commits made by students be pushed to the `development` branch for the mentors to review.

#### Command Line

```bash
git checkout development
```

#### GitHub Desktop

Click on `Current Branch` and then click on `origin/development`.

![Checkout Guide](/images/github-desktop-checkout.png)

### Making a Commit

Once you make a small but significant change to the robot code you'll need to commit it to Git. Making a commit will essentially store a snapshot of the project at that given point. This is nice for looking at the project back in time if needed. **Please ensure that before making a commit that you are on the `development` branch. See [Checking Your Git Branch](#checking-your-git-branch) for info on how to check.**

#### Command Line

```bash
git add -A
git commit -m "Brief explanation of what you did"
```

#### GitHub Desktop

First ensure that all changed files are checked in the left column. Add a commit message and optional description in the bottom of the left column. Press `Commit to development` to make the commit. Repeat this process every time you make an incremental change. After several of these commits you can push them as shown in the section below.

![Commit Guide](/images/github-desktop-commit.png)

### Pushing Your Commits to GitHub

Even though you have made some commits those still remain on your machine only. To make sure GitHub has your changes you will need to perform a push. **Please ensure that before pushing your commits that you are on the `development` branch. See [Checking Your Git Branch](#checking-your-git-branch) for info on how to check.**

#### Command Line

```bash
git push
```

#### GitHub Desktop

Click on `Push Origin` to push your locally saved commits to GitHub.

![Push Guide](/images/github-desktop-push.png)

### Pulling Changes

Often one of the other programmers will push their changes to GitHub and by association make your local copy out of date. You can update your local copy by performing a pull. You will need to make sure that you do not have any uncommited changes before doing this. If you have changes you will need to commit them before pulling.

#### Command Line

```bash
git pull
```

#### GitHub Desktop

Go to `Repository -> Pull`. This will pull the most recent changes to your machine from GitHub.

![Pull Guide](/images/github-desktop-pull.png)

### Submitting a Pull Request

The way our robot code repo is set up is that there are two branches: `main` and `development`. Students are only allowed to commit to the `development` branch but they still need a way to eventually get their code brought into the `main` branch. This is done via a Pull Request. A Pull Request allows a student to essentially flag their code for review from a mentor. During the Pull Request process if a mentor deems that the code does not meet the team's standards then the request is flagged for changes. Those changes need to be made before the Pull Request will be completed. When the code in the request is deemed to meet the team's standards then a mentor will approve the Pull Request and merge your code into the `main` branch. This may seem unneccesary but this allows us as a team to maintain high code standards and always ensure that committed code does not hinder the ability of the robot to run properly at competition.

To submit a Pull Request go to the [2022-RapidReact repo](https://github.com/BlueCrewRobotics/2022-RapidReact/tree/development). Towards the top of the page there will be a "Contribute" button that drops down a button you'll need to press titled "Open pull request. This will open a page where you will need to provide a title and description of the changes that you have made. In the right column there you will want to add `matthewgallant`, `camhammond`, and `LucienHmd` as reviewers. You can then open the Pull Request.

![Pull Request Guide](/images/github-pull-request.png)

### Checking Your Git Branch

Sometime you need to know which Git branch is currently the default on your machine.

#### Command Line

```bash
git checkout
```

#### GitHub Desktop

To check which branch your machine is currently see the button at the top that says `Current Branch`.
