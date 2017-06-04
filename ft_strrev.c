char *ft_strrev(char *str)
{
	int end;
	int begin;			

	end = ft_strlen(str) - 1;
	begin = 0;
	while(end > begin)
	{
		ft_swap(str + begin, str + end);
		begin++;
		end--;
	}
	return str;
}