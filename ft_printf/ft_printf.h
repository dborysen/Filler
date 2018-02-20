/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:31:21 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/11 16:31:25 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"

typedef struct	s_flags
{
	char	size_flag;
	char	star;
	char	type;
	char	plus;
	char	minus;
	char	zero;
	char	hash;
	char	space;
	int		precision;
	int		width;
	int		bnum;
}				t_flags;

typedef struct	s_phelp
{
	int		i;
	int		temp;
	int		t_bnum;
	char	*tmp_str;
	void	(*ft_output)(t_flags*, long long);
	void	(*ft_outputu)(t_flags*, unsigned long long);
	va_list	a;
}				t_phelp;

void			ft_which_output(char type, void (**ft_output)
								(t_flags *, long long));
void			ft_which_output_u(char type, void (**ft_outputu)
								(t_flags *, unsigned long long));
void			fill_flags(t_flags **flags, t_phelp **help);
void			free_lists(t_flags **flags, t_phelp **help);
int				free_help(const char *s, t_flags **flags, t_phelp **help);
void			output_help(const char *s, t_flags *flags, t_phelp *help);
void			ft_output_obig(t_flags *flags, long long argptr);
void			ft_output_xbig(t_flags *flags, long long argptr);
void			ft_output_ubig(t_flags *flags, unsigned long long argptr);
void			ft_output_p(t_flags *flags, long long argptr);
void			ft_output_b(t_flags *flags, unsigned long long argptr);
void			ft_output_cbig(t_flags *flags, long long argptr);
void			ft_output_sbig(t_flags *flags, long long argptr);
void			ft_output_c(t_flags *flags, long long argptr);
void			ft_output_dbig(t_flags *flags, long long argptr);
void			ft_zero_search(char *s, t_flags *flags);
void			ft_width_search(char *s, t_flags *flags);
void			ft_precision_search(char *s, t_flags *flags);
void			ft_is_a_flag(char *s, t_flags *flags);
int				ft_count_digit(long long n);
int				ft_char_place(char *str, char c);
size_t			ft_count_flags(const char *s);
char			ft_corrent_type(const char *s);
char			ft_priority_flag(char *s);
char			ft_char_priority_flag(char *s);
void			ft_output_d(t_flags *flags, long long argptr);
void			ft_output_s(t_flags *flags, long long argptr);
void			ft_output_u(t_flags *flags, unsigned long long argptr);
void			ft_output_x(t_flags *flags, long long argptr);
void			ft_output_o(t_flags *flags, long long argptr);
int				ft_count_digit(long long n);
int				ft_printf(const char *s, ...);
void			ft_print_unicode(int n, t_flags *flags);
void			left_alignment_d(t_flags *flags, long long argptr);
void			right_alignment_d(t_flags *flags, long long argptr);
void			left_alignment_u(t_flags *flags, unsigned long long argptr);
void			right_alignment_u(t_flags *flags, unsigned long long argptr);
void			left_alignment_x(t_flags *flags, char *argptr);
void			right_alignment_x(t_flags *flags, char *argptr);
void			left_alignment_o(t_flags *flags, char *argptr);
void			right_alignment_o(t_flags *flags, char *argptr);

#endif
