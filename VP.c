typedef struct node 
{
    char data;
    struct node *prev;
}node;

node *top = NULL;
int size = 0;


node *new_node(char data)
{
    node *stack_node = malloc(sizeof(node));
    if (!stack_node)
        return NULL;
    stack_node->data = data;
    stack_node->prev = NULL;
    return stack_node;
}

int push(char data)
{
    node *stack_node = new_node(data);
    if (!stack_node)
        return -1;
    stack_node->prev = top;
    top = stack_node;
    size++;
    return 0;
}

char pop()
{
    node *temp;
    char temp_data;
    if (size == 0)
    {
        return '\0';
    }
    temp_data = top->data;
    temp = top;
    top = top->prev;
    free(temp);
    size--;
    return (temp_data);
}

bool is_open(char c)
{
    return (c == '{' || c == '(' || c == '[');
}

bool is_close(char c)
{
    return (c == '}' || c == ')' || c == ']');
}

bool match(char a, char b)
{
    return ((a == '(' && b == ')') ||
            (a== '[' && b == ']') ||
            (a == '{' && b == '}'));
}

bool    isValid(char* s)
{
    int pos;
    int i, j;

    i = 0;
    j = 0;
    pos = 0;
    if ((strlen(s) % 2) != 0)
        return false;
    while (s[pos] !='\0')
    {
        while (s[pos] != '\0' && is_open(s[pos]))
        {
            push(s[pos]);
            pos++;
            i++;
        }
        while (s[pos] != '\0' && is_close(s[pos]))
        {
            char temp;
            temp = pop();
            if(!match(temp,s[pos]))
            {
                return false;
            }
            j++;
            pos++;
        }
    }
    if (i != j)
    {
        return false;
    }
    return true;
}
