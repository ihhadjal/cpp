#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str = argv[1];
        int tmp;
        int c = 0;
        std::stack<int> stack;

        for (int i = 0; str[i]; i++)
        {
            if (str[i] == ' ')
                continue;
            else if (isdigit(str[i]))
                stack.push(std::atoi(str + i));
            else if (str[i] == '+')
            {
                tmp = stack.top();
                stack.pop();
                stack.top() += tmp;
            }
            else if (str[i] == '-')
            {
                tmp = stack.top();
                stack.pop();
                stack.top() -= tmp;
            }
            else if (str[i] == '*')
            {
                tmp = stack.top();
                stack.pop();
                stack.top() *= tmp;
            }
            else if (str[i] == '/')
            {
                tmp = stack.top();
                if (tmp == 0)
                {
                    std::cout << "Error: cant divide by zero\n";
                    exit (1);
                }
                stack.pop();
                stack.top() /= tmp;
            }
            else
            {
                c++;
                break;
            }
        }
        if (c == 1 || stack.size() > 1)
            std::cout << "Error\n";
        else
            std::cout << stack.top() << '\n';
    }
    else
        std::cout << "Error: arguments error\n";
}