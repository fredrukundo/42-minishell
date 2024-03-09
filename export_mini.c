/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_mini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:13:02 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:13:03 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		env_sort(t_list *export);
static t_list	*env_copy(t_list *env, t_list *lst);
static int		env_srch(t_d *data, char	*line);
static int		key_srch(char **env, t_list *temp, char **arr, char *var);

void	ft_export(t_d *data, char **arg)
{
	t_list	*export;
	int		i;
	int		len;

	export = NULL;
	len = array_size(arg);
	if (len == 1)
		env_sort(env_copy(data->env, export));
	else
	{
		i = 0;
		while (++i < len)
			if (arg[i])
				if (env_srch(data, arg[i]) == 0)
					ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(arg[i])));
	}
	if (data->exstatus != 0)
		return ;
	data->exstatus = 0;
}

static t_list	*env_copy(t_list *env, t_list *lst)
{
	while (env != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(env->content)));
		env = env->next;
	}
	return (lst);
}

static int	env_srch(t_d *data, char *var)
{
	t_list	*temp;
	char	**arr;
	char	**env;

	temp = data->env;
	arr = key_value_spliting(var, '=');
	if (key_check(arr[0]) == 0)
	{
		ft_printf_fd(2, "export: '%s': not a valid identifier\n", arr[0]);
		data->exstatus = 1;
		ft_free_str_arr(&arr);
		return (2);
	}
	env = NULL;
	if (key_srch(env, temp, arr, var) == 1)
		return (1);
	ft_free_str_arr(&arr);
	return (0);
}

static int	key_srch(char **env, t_list *temp, char **arr, char *var)
{
	while (temp)
	{
		env = key_value_spliting(temp->content, '=');
		if (ft_strcmp(env[0], arr[0]) == 0)
		{
			if (arr[1])
			{
				free(temp->content);
				temp->content = ft_strdup(var);
			}
			ft_free_str_arr(&env);
			ft_free_str_arr(&arr);
			return (1);
		}
		ft_free_str_arr(&env);
		temp = temp->next;
	}
	return (0);
}

static void	env_sort(t_list *export)
{
	t_list	*temp1;
	t_list	*temp2;
	int		swapped;

	temp2 = NULL;
	while (true)
	{
		temp1 = export;
		swapped = 0;
		while (temp1->next != temp2)
		{
			if (ft_strcmp(temp1->content, temp1->next->content) > 0)
			{
				ft_swap_lst(temp1);
				swapped = 1;
			}
			temp1 = temp1->next;
		}
		temp2 = temp1;
		if (!swapped)
			break ;
	}
	export_print(export);
	lst_free(export);
}
