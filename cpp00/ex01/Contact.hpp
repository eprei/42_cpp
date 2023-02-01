#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact{

public:

	Contact(void);
	~Contact(void);

	static int		get_nb_inst(void);
	static void		add_nb_inst(void);

	std::string		get_first_name(void) const;
	std::string		get_last_name(void) const;
	std::string		get_nickname(void) const;
	std::string		get_phone_number(void) const;
	std::string		get_darkest_secret(void) const;
	int				get_index(void) const;

	void			set_first_name(std::string str);
	void			set_last_name(std::string str);
	void			set_nickname(std::string str);
	void			set_phone_number(std::string str);
	void			set_darkest_secret(std::string str);
	void			set_index(int i);

	void			print_contact(void) const;
	void			print_full_contact(void) const;

private:

	static int	_nb_inst;

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	int			_index;
};

#endif
