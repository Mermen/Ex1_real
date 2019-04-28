#include <iostream>
#include <string>
#include <vector>

struct letter
{
	std::string a;
	std::vector<std::string> a_next;
	std::vector<int> num_a_next;
	int n_next=0;
	letter* right=NULL;
};

int find(letter **start, std::string n, letter **pos) {
	if (*start == NULL)
	{
		return 0;
	}
	else
	{
		letter* c = *start;
		while (c != NULL)
		{
			if (c->a == n)
			{
				*pos = c;
				return 1;
			}
			c = c->right;
		}
		return 0;
	}
}

void push(letter **start, letter **end, std::string n) {
	if (*start == NULL)
	{
		letter *c = new letter;
		c->a = n;
		*start = c;
		*end = c;
	}
	else
	{
		letter *c = new letter;
		c->a = n;
		(*end)->right = c;
		*end = (*end)->right;
	}
}

int main() 
{
	int n;
	std::cin >> n;
	std::string s;
	std::string s_temp_1="";
	std::string s_temp_2="   ";
	letter* start = NULL;
	letter* end = start;
	int flag;
	letter* c=NULL;
	letter* c1=NULL;
	int flag_find2;
	for (int i = 0; i < n; i++)
	{
		std::cin >> s;
		for (int j = 0; j < s.length()-2; j++)
		{
			flag = 1;
			s_temp_2[0] = s[j];
			s_temp_2[1] = s[j + 1];
			s_temp_2[2] = s[j + 2];
			flag_find2 = find(&start, s_temp_2, &c);
			if ((!flag_find2)&&(s_temp_1 == ""))
			{
				push(&start, &end, s_temp_2);
			}
			else if (s_temp_1!="")
			{
				
				if (flag_find2)
				{
					for (int k = 0; k < c1->n_next; k++)
					{
						if (c1->a_next[k] == s_temp_2)
						{
							c1->num_a_next[k]++;
							flag = 0;
							break;
						}

					}
					if(flag)
					{
						
						c1->a_next.push_back(s_temp_2);
						c1->num_a_next.push_back(1);
						c1->n_next++;
					}
				}
				else
				{
					push(&start, &end, s_temp_2);
					c1->a_next.push_back(s_temp_2);
					c1->num_a_next.push_back(1);
					c1->n_next++;
				}
			}
			s_temp_1 = s_temp_2;
			if (end->a== s_temp_2)
			{
				c1 = end;
			}
			else
			{
				c1 = c;
			}
		}
		s_temp_1 = "";

	}//
	c = start;
	int v = 0;
	int e = 0;
	while (c!=NULL)
	{
		v++;
		e += c->n_next;
		c = c->right;
	}
	c = start;
	for (int i = 0; i < 1000000000; i++)
	{
		v++;
		e--;
	}
	for (int i = 0; i < 1000000000; i++)
	{
		v--;
		e++;
	}
	std::cout << v << std::endl;
	std::cout << e << std::endl;
	
	while (c != NULL)
	{
		for (int i = 0; i < c->n_next; i++)
		{
			std::cout << c->a + ' ' + c->a_next[i] + ' ' << c->num_a_next[i] << '\n';
		}
		c = c->right;
	}
	system("pause");
}