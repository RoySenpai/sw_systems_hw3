/*
 *  Software Systems Course Assignment 3
 *  Copyright (C) 2022  Roy Simanovich

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>

/* Max characters per line. */
#define LINE 256

/* Max characters per word. */
#define WORD 30

int get_line(char s[]);

int getword(char w[]);

int substring(char * str1, char * str2);

int similar(char *s, char *t, int n);

void print_lines(char * str);

void print_similar_words(char * str);

int main() {
    char word[WORD] = { 0 }, choice = '\0';

    getword(word);
    scanf(" %c\n", &choice);

    if (choice == 'a')
        print_lines(word);

    else if (choice == 'b')
        print_similar_words(word);

    return 0;
}

/*
 * Function:  get_line
 * --------------------
 * Reads one line from an input.
 *
 *  s: an array where we put the line.
 * 
 *  return: total characters read by the function,
 *              max of LINE characters.
 */
int get_line(char s[]) {
    int i = 0;

    for (i = 0; i < LINE; ++i)
    {
        if (scanf("%c", &(*(s + i))) == EOF)
        {
            *(s + i) = '\0';
            break;
        }

        if (*(s + i) == '\n')
        {
            *(s + i) = '\0';
            break;
        }
    }

    if (i == LINE)
        *(s + i - 1) = '\0';

    return i;
}

/*
 * Function:  getword
 * --------------------
 * Reads one word from an input.
 *
 *  s: an array where we put the word.
 * 
 *  return: total characters read by the function,
 *              max of WORD characters.
 */
int getword(char w[]) {
    int i = 0;

    for (i = 0; i < WORD; ++i)
    {
        if (scanf("%c", &(*(w + i))) == EOF)
        {
            *(w + i) = '\0';
            break;
        }

        if (*(w + i) == '\n' || *(w + i) == '\t' || *(w + i) == ' ')
        {
            *(w + i)= '\0';
            break;
        }
    }

    if (i == WORD)
        *(w + i - 1) = '\0';

    return i;
}

/*
 * Function:  substring
 * --------------------
 * Checks if a string is a substring of another string.
 *
 *  str1: a string.
 * 
 *  str2: substring to check.
 * 
 *  return: 1 if str2 is a substring of str1,
 *              0 elsewise.
 */
int substring(char * str1, char * str2) {
    int str1_len = strlen(str1), str2_len = strlen(str2), matchCount, i, j;

    for (i = 0; i <= str1_len - str2_len; ++i)
    {
        matchCount = 0;

        for (j = 0; j <= str2_len; ++j)
        {
            if (*(str1 + i + j) == *(str2 + j))
                ++matchCount;
        }

        if (matchCount >= str2_len)
            return 1;
    }

    return 0;
}

/*
 * Function:  similar
 * --------------------
 * Checks if a string is similar to other string,
 *  by deleting n characters.
 *
 *  s: a string.
 * 
 *  t: another string.
 * 
 *  n: number of characters to remove from s.
 * 
 *  return: 1 if s and t are similar,
 *              0 elsewise.
 */
int similar(char *s, char *t, int n) {
    int s_len = strlen(s), t_len = strlen(t), i = 0, j = 0;

    if (s_len - t_len != n)
        return 0;

    for (i = 0; i < s_len && j < t_len; ++i)
    {
        if (*(s + i) == *(t + j))
            ++j;
    }

    return (t_len == j);
}

/*
 * Function:  print_lines
 * --------------------
 * Prints all the lines that contains a substring of the word.
 *
 *  str: a word.
 */
void print_lines(char * str) {
    char line[LINE] = { 0 };

    while(get_line(line))
    {
        if (substring(line, str))
            printf("%s\n", line);
    }
}

/*
 * Function:  print_similar_words
 * --------------------
 * Prints all the words that are similar to the word,
 *  by at most 1 character deletion.
 *
 *  str: a word.
 */
void print_similar_words(char * str) {
    char word[WORD] = { 0 };

    while(getword(word))
    {
        if (similar(word, str, 1) || similar(word, str, 0))
            printf("%s\n", word);
    }
}