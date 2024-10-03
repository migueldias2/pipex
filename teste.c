int main(int argc, char **argv, char **envp) {
    if (argc < 5) {
        ft_putstr_fd("Invalid number of arguments\n", 2);
        return (1);
    }

    // Open input and output files
    int infile = open(argv[1], O_RDONLY);
    int outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Create pipes for commands
    int pipe_fds[2];
    pipe(pipe_fds);

    // Fork first process (cmd1)
    if (fork() == 0) {
        // In child 1 (cmd1)
        dup2(infile, STDIN_FILENO);  // Redirect input from file
        dup2(pipe_fds[1], STDOUT_FILENO);  // Redirect output to pipe
        close(pipe_fds[0]);  // Close unused read end
        execve(find_cmd(argv[2], envp), parse_cmd(argv[2]), envp);
        perror("execve");  // In case execve fails
        exit(1);
    }

    // Fork second process (cmd2)
    if (fork() == 0) {
        // In child 2 (cmd2)
        dup2(pipe_fds[0], STDIN_FILENO);  // Redirect input from pipe
        dup2(outfile, STDOUT_FILENO);  // Redirect output to file
        close(pipe_fds[1]);  // Close unused write end
        execve(find_cmd(argv[3], envp), parse_cmd(argv[3]), envp);
        perror("execve");  // In case execve fails
        exit(1);
    }

    // Close all open file descriptors in the parent
    close(infile);
    close(outfile);
    close(pipe_fds[0]);
    close(pipe_fds[1]);

    // Wait for child processes
    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);

    return 0;
}
