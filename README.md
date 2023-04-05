# OOStubBS by MBJ

A fork of the Studenten Betriebssystem, worked on by Martin, Benedict and Julius.


## Using git in this fork

The explanation was taken from: https://adiati.com/git-how-to-fetch-a-branch-from-the-upstream-to-the-local-repo-in-5-steps

### Cloning the repo

1. Clone as normal with `git@github.com:orjules/OOStubBS_MBJ.git`
2. Check if the upstream is set by running `git remote -v`. If not, run `git remote add upstream https://os.inf.tu-dresden.de/Studium/OSC/SS2023/oostubs.git`
3. Fetch from the upstream with `git fetch upstream`. If there is a new branch pull it with `git pull upstream <branch name>`

### Checking for a new task
1. Fetch from the upstream with `git fetch upstream`. If there is a new branch pull it with `git pull upstream <branch name>`
2. Merge the branch if necessary
3. Push the changes to origin by running `git push origin`

### Commiting your work
1. Add your work with `git add .`
2. Commit your work with `git commit -m"Sample message"`. Check out [this guide](https://gist.github.com/luismts/495d982e8c5b1a0ced4a57cf3d93cf60#write-good-commit-messages) for well formed commit messages.
3. Pull the current state with `git pull origin` and merge if necessary
4. Push your work to origin by running `git push origin`


