/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:04:21 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 14:28:52 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
// printf
// perror
# include <unistd.h>
// write
// read
// access
// fork
// getcwd
// chdir
// unlink
// execve
// dup
// dup2
// pipe
// isatty
// ttyname
// ttyslot
# include <stdlib.h>
// malloc
// free
// exit
// getenv
# include <fcntl.h>
// open
// close
# include <sys/wait.h>
// wait
// waitpid
// wait3
// wait4
# include <signal.h>
// signal
// sigaction
// sigemptyset
// sigaddset
// kill
# include <sys/stat.h>
// stat
// lstat
// fstat
# include <dirent.h>
// opendir
// readdir
// closedir
# include <string.h>
// strerror
# include <readline/history.h>
# include <readline/readline.h>
// readline
// rl_clear_histroy
// rl_on_new_line
// rl_replace_line
// rl_redisplay
// add_history
# include <sys/ioctl.h>
// ioctl
# include <termios.h>
// tcgetattr
// tcsetent
# include <term.h>
# include <termcap.h>
// tgetent
// tgetflag
// tgetnum
// tgetset
// tgoto
// tputs
# include "./libft/libft.h"
# include <errno.h>

# define DEFA 10
# define ABLE 22
# define REDD 11
# define DOLL 44
# define SPCE 88
# define PIPE 99
# define ERRO 999

# define REIN 201
# define REOU 202
# define HERE 203
# define APPN 204

# define NONE 100
# define SING 111
# define DOUB 112

# define ALLO 22
# define DENY 999

typedef struct s_env
{
	char			*data;
	int				flag;
	struct s_env	*next;
}					t_env;

typedef struct s_global
{
	int				last_state;
	int				bp_stdin;
	int				bp_stdout;
	char			*shell_name;
	t_env			*env;
}					t_global;

typedef struct s_shell
{
	char			*cmd_line;
}					t_shell;

typedef struct s_parse
{
	char			*s;
	int				type;
	int				in_quote;
	struct s_parse	*next;
}					t_parse;

typedef struct s_red
{
	char			*red;
	char			*file;
}					t_red;

typedef struct s_cmd
{
	int				num;
	pid_t			pid;
	char			**arg;
	struct s_red	*red;
	int				state;
	char			*rein;
	int				limi;
	char			*infi;
	char			*reou;
	char			*oufi;
	int				fd[2];
	int				infd;
	int				oufd;
	struct s_cmd	*next;
}					t_cmd;

// ft_exit
// error_parse.c
void				error_nothing(void);
void				error_parse(t_parse **lst);

// error_cmd.c
void				error_cmd(t_parse **lst, t_cmd **cmd);

// error_exe.c
void				error_strerror(t_parse **lst, t_cmd **cmd);
int					error_file(char *file, t_parse **lst, t_cmd **cmd);
void				error_child(t_parse **lst, t_cmd **cmd);
void				error_invalid_cmd(char *command, t_parse **lst,
						t_cmd **cmd);
int					error_token(char *token, t_parse **lst, t_cmd **cmd);

// error_prompt.c
void				error_prompt_line(char *line);
void				error_env(t_env **lst, t_env *new);
void				error_init(void);

//error_builtin
int					error_builtin_cd(char *cmd, char *arg, char *msg);
int					error_builtin_env(char *cmd, char *arg, char *msg);
int					error_builtin_exit(char *cmd, char *arg, char *msg);

// parse
// parse.c
t_parse				*parse_main(char *str);
void				sequence(t_parse **lst);

// parse_node.c
int					add_parse(t_parse **lst, char *s, int type, int quote);
void				clear_parse(t_parse **lst);
void				delone_parse(t_parse *lst);
t_parse				*last_parse(t_parse *lst);
t_parse				*new_parse(char *s, int type, int quote);

// ft_strndup.c
char				*ft_strndup(const char *s1, size_t n);

// separate_quote.c
void				separate_quote(t_parse **lst);
void				separate_by_quote(t_parse **lst, t_parse **cur, int i,
						char flag);
char				**dividing(t_parse **lst, char *s, int open, int close);

// separate_quote_try.c
void				try_sing(t_parse **lst, t_parse **cur, char **sep);
void				try_doub(t_parse **lst, t_parse **cur, char **sep);
void				try_last(t_parse **lst, t_parse **cur, char **sep);

// trans_dollar.c
void				trans_dollar(t_parse **lst);
void				trand_dollar_loop(t_parse **lst, char **seg);
char				*ft_join_split(char **seg);
void				change_dollar(t_parse **lst, char **seg, int i);
void				error_seg_malloc(t_parse **lst, char **seg);

// split_dollar.c
char				**split_dollar(char *s);
void				get_seg_dollar(char *s, int *i, int *seg);
int					set_start_end_dollar(char *s, int *i, int *blk,
						char ***res);
int					error_res(char ***res, int *blk);
void				free_split(char **res);

// separate_space.c
void				separate_space(t_parse **lst);
void				separate_space_loop(t_parse **lst, t_parse **cur,
						char **seg, int i);
char				**split_space(char *s);
void				get_seg_space(char *s, int *i, int *seg);
int					set_start_end_space(char *s, int *i, int *blk, char ***res);

// separate_pipe.c
void				separate_pipe(t_parse **lst);
void				separate_pipe_loop(t_parse **lst, t_parse **cur, char **seg,
						int i);
char				**split_pipe(char *s);
void				get_seg_pipe(char *s, int *i, int *seg);
int					set_start_end_pipe(char *s, int *i, int *blk, char ***res);

// separate_red.c
void				separate_red(t_parse **lst);
void				separate_red_loop(t_parse **lst, t_parse **cur, char **seg,
						int i);
char				**split_red(char *s);
void				get_seg_red(char *s, int *i, int *seg);
int					set_start_end_red(char *s, int *i, int *blk, char ***res);

// del_empty.c
void				del_empty(t_parse **lst);
void				del_parse(t_parse **lst, t_parse **cur, t_parse **pre);

// change_able.c
void				change_able(t_parse **lst);

// union_able.c
void				union_able(t_parse **lst);
int					set_first_parse(t_parse **tmp, t_parse **cur, t_parse **pre,
						char **s);
void				join_able(t_parse **lst, t_parse **tmp, t_parse **cur,
						t_parse **pre);

// del_space.c
void				del_space(t_parse **lst);

// check_cmd_error.c
void				check_cmd_error(t_parse **lst);
void				set_cmd_error(t_parse **lst);

// exe
// cmd_node.c
void				add_cmd(t_cmd **lst, t_cmd *cmd);
void				clear_cmd(t_cmd **lst);
void				delone_cmd(t_cmd *lst);
t_cmd				*last_cmd(t_cmd *lst);
t_cmd				*new_cmd(void);

// make_cmd.c
t_cmd				*make_cmd(t_parse *cur, int i);
void				init_cmd(t_cmd *cmd, int red, int arg);
void				count_arg_red(t_parse *cur, int *red, int *arg);
int					check_cmd_args(t_cmd *cmd);

// set_cmd.c
void				set_cmd(t_cmd *cmd, t_parse **cur, int *red, int *arg);
void				set_red(t_cmd *cmd);
int					set_limit(t_cmd *cmd);

// make_error_cmd.c
t_cmd				*make_error_cmd(t_parse *cur);

// make_cmd_list.c
t_cmd				*make_cmd_list(t_parse **lst);
void				make_cmd_loop(t_parse **lst, t_parse **cur, t_cmd **cmd,
						int *i);

// execute.c
int					execute(char *s);
void				execute_fork(t_parse **lst, t_cmd **cmd, int i);
int					wait_every_pid(t_parse **lst, t_cmd **cmd);
int					if_deny(t_parse **lst, t_cmd **cmd);

// execute_func.c
int					check_exit(t_parse **lst, t_cmd **cmd);
int					init_exe(t_parse **lst, t_cmd **cmd, char *s);
int					here_doc_fork(t_parse **lst, t_cmd **cmd);
int					end_exe(t_parse **lst, t_cmd **cmd);

// make_heredoc.c
void				make_heredoc(t_parse **lst, t_cmd **cmd);
void				here_doc_loop1(t_parse **lst, t_cmd **cmd, t_cmd **cur);
int					make_heredoc_file(char *file, int num);
int					check_heredoc(int fd, char *file);
int					here_doc_loop2(int fd, char *file);

// open_heredoc.c
void				open_heredoc(t_parse **lst, t_cmd **cmd);

// make_heredoc_utils.c
int					end_heredoc_malloc(int fd, char *tmp);
int					end_heredoc_error(int fd, char *tmp);
int					end_heredoc(int fd, char *tmp);

// here_doc_dollar.c
char				*here_doc_dollar(char *s);
char				**set_here_doc_seg(char *s);
int					set_here_doc_start_end(char *s, int *i, int *blk,
						char ***segment);
int					here_doc_change_dollar(char **seg, int i);

// here_doc_dollar_utils.c
int					here_doc_dollar_tmp(char **seg);
int					set_start_end_dollar_here(char *s, int *i, int *blk,
						char ***res);

// utils.c
char				*strjoin_ascii(char *str, int num);
int					ft_strcmp(char *s1, char *s2);

// initcmd.c
t_cmd				*initcmd(t_parse **lst);
int					file_exist(t_parse **lst, t_cmd **cmd, t_cmd *cur);
void				init_file_fd(t_parse **lst, t_cmd **cmd, t_cmd *cur);

// parent_main.c
void				parent_main(t_cmd **cmd, pid_t pid, int i);

// child_main.c
void				child_main(t_parse **lst, t_cmd **cmd, int i);
t_cmd				*find_cmd(t_cmd **cmd, int i);
t_cmd				*find_pre(t_cmd **cmd, int i);
void				close_all_pipe(t_cmd **cmd);
int					set_redirection(t_cmd *cur, t_cmd *pre);

// exec_cmd.c
void				exec_cmd(t_parse **lst, t_cmd **cmd, t_cmd *cur);
char				**dup_arg(char **arg);
void				free_split_cmd(char **path);
char				*ft_strdup_no_gc(const char *s1);
void				free_split_no_gc(char **path);

// exec_utils.c
char				*get_cmd_path(t_cmd *cur, char **path, int i);
void				exe_loop(t_parse **lst, t_cmd **cmd, t_cmd *cur,
						char **path);

// is_builtin.c
int					is_builtin(t_cmd *cur);
int					is_builtin_bool(t_cmd *cur);

// exe_sig_handle.c
void				exe_ctl_c(int signum);

// ft_split_non.c
char				**ft_split_non(char const *s, char c);

// make_env.c
char				**make_env(t_env **env);

//prompt
// minishell.c
void				print_ascii1(void);
void				print_ascii2(void);
void				print_ascii3(void);
void				print_ascii4(void);

//utils.c
char				*ft_strjoin_free(char *s1, char const *s2);
int					global_init(char **env);
char				*ft_getenv(char *dest);
int					is_cmd_line_valid(char *cmd_line);
void				unlink_heredoc(void);

//utils2.c
int					is_env_node_same(t_env **env_list, char *line);
void				signal_init(void);
void				dup2_std_to_bp(void);

//env_list.c
int					add_env(t_env **env_list, char *line, int flag);
t_env				*last_env(t_env *curr);
void				delone_env(t_env *list);
void				clear_env(t_env **list);
void				change_envnode(t_env **list, char *flag, char *path);

//prompt.c
void				prompt(void);
char				*make_prompt(char *prompt);
char				*get_prompt_line(char *line);
char				*find_pwd(char *line);
char				*get_pwd_line(char *line, char *pwd_line);

//sig_handler.c
void				handle_ctrl_c(int signum);
void				handle_ctrl_d(int errocode);
void				handle_ctrl_c_f(int signum);
void				handle_ctrl_c_h(int signum);
void				sig_exit(int signum);

//sig_handler2.c
void				handle_ctrl_back_f(int signum);
void				handle_ctrl_back(int signum);
// void				handle_f_ctrl_c(int signum);

//builtin
//echo.c
int					ft_echo(char **argv);
int					is_n_option(char *argv);

//cd.c
int					ft_cd(char **argv);
int					do_cd(char **argv);
void				change_pwd(char *path);

//pwd.c
int					ft_pwd(char **argv);

//environ.c
int					ft_unset(char **argv);
int					ft_env(char **argv);
int					ft_export(char **argv);
void				remove_envnode(size_t len, char *argv);
int					is_env_arg_valid(char **argv);
char				**split_node(void);
int					env_lstsize(t_env *lst);
char				**sort_str(int size, char **str);
int					count_str(char **str);
void				print_export(char **str);
int					is_export_arg_valid(char *argv);
//exit.c
int					ft_exit(char **argv);
int					ft_atoll(char *str);

#endif
