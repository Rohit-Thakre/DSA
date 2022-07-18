// find length of string

#include <stdio.h>

void ASCII_value()
{
    printf("enter the character to find its ASCII value\n");
    char input;
    scanf("%c", &input);
    printf("the ASCII value is : %d", input);
}
void len(char array[])
{
    int i = 0;
    while (array[i] != '\0')
        i++;

    printf("the character count is : %d", i);
}

void to_upper(char string[])
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - 32;
        i++;
    }
    printf("\n\nthe swaped string is : %s", string);
}

void to_lower(char string[])
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
            string[i] = string[i] + 32;
        i++;
    }
    printf("\n\nthe swaped string is : %s", string);
}

void toggle_Case()
{
    char input[10];
    printf("Enter the string to toggle the case.\n");
    scanf("%s", &input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        // if (input[i] >= 65 && input[i] <= 90)
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] = input[i] + 32;

        else if (input[i] >= 'a' && input[i] <= 'z')
            input[i] = input[i] - 32;
    }

    printf("The toggled string is : %s", input);
}

void validate(char string[])
{
    int i = 0;
    while (string[i] != '\0')
    {
        // only characters are allowed in this case

        if (!(string[i] <= 'a' || string[i] >= 'z') && !(string[i] <= 'A' || string[i] >= 'Z'))
        {
            printf("\n\nInvalid string\n");
            break;
        }
        i++;
    }
    printf("\n\nthe string is acceptable\n");
}

void count()
{
    char input[] = {"Hello there i'm groot"};
    // printf("Enter the string to count vovels,consonants, word.\n");
    // scanf("%s", &input);
    printf("The entered string is:\n %s\n", input);
    int vcount = 0, ccount = 0, wcount = 1;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
            vcount++;

        else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            ccount++;

        else if (input[i] == ' ' && input[i - 1] != ' ')
            wcount++;
    }

    printf("\nVovels: %d\nConsonant: %d\nword: %d", vcount, ccount, wcount);
}
void reverse(char string[])
{
    int i = 0, j = 0;
    char temp;
    while (string[j] != '\0')
        j++;

    j = j - 1;
    for (i, j; i < j; i++, j--)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }

    printf("\nThe reversed string is : %s\n\n", string);
}

void compare()
{
    char s1[] = "Palindrome";
    char s2[] = "Palindromm";

    int i = 0, j = 0, flag = 1;
    for (i, j; s1[i] != '\0'; i++, j++)

        if (s1[i] != s2[j])
        {
            printf("\nthe string is mismatching.\n");
            flag = 0;
            break;
        }
    if (flag != 0)
        printf("both the strings are same");
}

void Palindrome()
{
    char string[] = "madam";

    int i = 0, j = 0, flag = 0;

    for (i; string[i] != 0; i++)
    {
    }
    i--;

    for (j, i; j < i; i--, j++)
    {
        printf("istring[%d]:%c\njstring[%d]:%c\n\n", i, string[i], j, string[j]);
        if (string[j] != string[i])
        {
            printf("The string is not Palindrome.\n");
            flag = 0;
            break;
        }

        else
            flag = 1;
    }
    if (flag == 1)
        printf("the string is palindrome\n");
}

void duplicated()
{
    // for lower case only;
    char string[] = "findiniiidg";

    int i = 0;
    int count = 1;

    for (i; string[i] != '\0'; i++)
    {
        // printf("iteration :%d\n", i);
        count = 1;
        for (int j = i + 1; string[j] != '\0'; j++)
        {

            if (string[i] == string[j])
            {
                string[j] = '0';
                // printf("string[%d] = %c\n", j, '0');
                count++;
            }
        }

        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') && count > 1)
            printf("%c occured %d times\n", string[i], count);
    }
}

void duplicated_Hashing()
{
    // for lower case only;
    char string[] = "findingnnumbersf";

    char temp[26] = {0};

    int i = 0;
    for (i; string[i] != '\0'; i++)
        temp[string[i] - 97]++;

    for (i = 0; i < 26; i++)
    {
        if (temp[i] > 1)
        {
            printf("%c occured %d times.\n", i + 97, temp[i]);
        }
    }
}

void duplicated_bit_Oprator()
{
    char string[] = "finding";
    long int h = 0, x = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        x = 1;
        x = x << (string[i] - 97);
        if ((x & h) > 0)
            printf("%c is duplicated.\n", string[i]);

        else
            h = x | h;
    }
}

void permutation(char s[], int k)
{
    static char res[10];
    static int A[10] = {0};
    int i;
    if (s[k] == '\0')
        printf(" %s ", res);

    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[i] = s[i];
                A[i] = 1;
                permutation(s, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    system("cls");
    system("color a");
    char string[10] = "string";
    len(string);
    to_upper(string);

    char upper_str[10] = "INCLUDE";
    to_lower(upper_str);
    char check[10] = "Afhdssj";
    validate(check);

    reverse(string);

    ASCII_value();

    Palindrome();
    toggle_Case();
    count();
    compare();
    Palindrome();
    duplicated();
    duplicated_Hashing();
    duplicated_bit_Oprator();

    char str[] = "ABC";
    permutation(str, 0);

    return 0;
}