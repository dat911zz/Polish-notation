void convertInfixToPostfix(char* P, char* Q)//((6+4)/2+7)/3-(1+2)*2)
{											//1*2+3*((4-5)+6)/7
											//3*(2+6*2/3–1)–2*3/2+1
	Stack<char> s;
	char tmp;
	int j = 0;
	initStack(s);
	push(s, '(');//Them ( vao stack
	showStack(s);
	for (int i = 0; i < strlen(P); i++)
	{
		//p = createNode(P[i]);
		if (P[i] >= '0' && P[i] <= '9')//Neu P la toan hang
		{
			Q[j++] = P[i];
		}
		else
		{
			if (P[i] == '(')//Neu P la dau ( thi day vao stack
			{
				push(s, P[i]);
				showStack(s);
			}
			else
			{
				if (P[i] == '^' || P[i] == '*' || P[i] == '/' || P[i] == '+' || P[i] == '-')//Neu P la toan tu 
				{
					while (s.top != NULL && checkPriority(P[i]) <= checkPriority(s.top->info) && s.top->info != '(')//Kiem tra do uu tien
					{
						Q[j++] = pop(s);
					}
					push(s, P[i]);
					showStack(s);
				}
				else
				{
					if (P[i] == ')')
					{
						while (s.top != NULL && s.top->info != '(')
						{
							Q[j++] = pop(s);
							showStack(s);
						}
						pop(s);
						showStack(s);
					}
				}
			}
		}
	}
	while (s.top != NULL && s.top->info != '(')
	{
		Q[j++] = pop(s);
		showStack(s);
	}
	showStack(s);
	Q[j] = '\0';
}
int calc(char op, int x, int y)
{
	switch (op)
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}
int calculateInfix(char* Q)
{
	int x, y, result;
	Stack<int> s;
	initStack(s);
	for (int i = 0; i < strlen(Q); i++)
	{
		if (Q[i] >= '0' && Q[i] <= '9')
		{
			push(s, Q[i] - 48);
		}
		else
		{
			if (Q[i] == '^' || Q[i] == '*' || Q[i] == '/' || Q[i] == '+' || Q[i] == '-')
			{
				x = pop(s);
				y = pop(s);
				result = calc(Q[i], y, x);
				push(s, result);
			}
		}
	}
	return pop(s);
}
