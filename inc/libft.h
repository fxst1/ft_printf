#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
long				ft_pow(int value, unsigned int n);
char				*ft_itoa_base(int64_t value, int base, char *basestr);
char				*ft_itoa_base_unsigned(uint64_t value, int base, char *basestr);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);

void				*ft_memalloc(size_t size);

char				*ft_strchr(const char *str, int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **root, t_list *add);

#endif
