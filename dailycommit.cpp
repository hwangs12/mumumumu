/* This program will run to fill your daily commit history chart */
/* You will create a temporary repo and program will write meaningless text in readme file */
/* Prereq: download git have your credential ready for git and prepare to run cron job */

#include <cstdlib>
#include <iostream>
#include <string>
#include "stringrepalce.h"

int main()
{
    char *personal_access_token = getenv("PAT");
    char *repo_name = getenv("REPO");
    char *username = getenv("USERNAME");
    // char *passphrase = getenv("PASSPHRASE");
    char *create_remote_repo_command = "curl -L \
        -X POST \
        -H \"Accept: application/vnd.github+json\" \
        -H \"Authorization: Bearer <PAT_TOKEN>\" \
        -H \"X-GitHub-Api-Version: 2022-11-28\" \
        https://api.github.com/user/repos \
        -d '{\"name\":\"<REPO_NAME>\",\"description\":\"This is your au\",\"private\":false,\"is_template\":true}'";
    char *update_readme = "touch README.md";
    char *initialize_git = "git init";
    char *add_text = "echo mamamia! >> README.md";
    char *stage_git = "git add .";
    char *git_commit = "git commit -m \"mamamia commit\"";
    char *add_git_remote = "git remote add origin git@github.com:<USERNAME>/<REPO_NAME>.git";
    char *git_push = "git push -u origin main";

    std::cout
        << "creating remote repository in github..." << std::endl;

    char *update_auth = str_replace(create_remote_repo_command, "<PAT_TOKEN>", personal_access_token);
    char *update_reponame = str_replace(update_auth, "<REPO_NAME>", repo_name);

    system(update_reponame);

    std::cout << "initiating git..." << std::endl;

    system(update_readme);
    system(initialize_git);
    std::cout << "happening here? 1";
    system(add_text);
    std::cout << "happening here? 2";
    system(stage_git);
    std::cout << "happening here? 3";
    system(git_commit);
    /* Make sure it's your username */
    char *add_git_with_username = str_replace(add_git_remote, "<USERNAME>", username);
    char *add_git_with_repo = str_replace(add_git_with_username, "<REPO_NAME>", repo_name);
    std::cout << "happening here? 4";
    system(add_git_with_username);
    // char *push_with_passphrase = str_replace(git_push, "<PASSPHRASE>", passphrase);
    std::cout << "happening here? 5";
    system(git_push);

    std::cout << "pushed to github please check your account in github" << std::endl;

    return 0;
}