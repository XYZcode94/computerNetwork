 while (*str)
    {
        if (*str != ' ' && *str != '\t' && *str != '\n')
        {
            if (in_word == 0)
            {
                count++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }

        str++;
    }