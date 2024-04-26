
// Not yet tested
void push_char(char **vec, int *len, char value) {
  int index = (*len)++;
  int is_power_of_two = (index & (index - 1)) == 0;
  if (index == 0) {
    *vec = (char *)malloc(3 * sizeof(char));
  } else if (index >= 2 && is_power_of_two) {
    *vec = (char *)realloc(*vec, (index * 2 + 1) * sizeof(char));
  }
  (*vec)[index] = value;
  (*vec)[index + 1] = '\0';
}

void pop_back_char(char **vec, int *len) {
  assert(*len != 0 && "string is empty.");
  int index = --(*len);
  (*vec)[index] = '\0';
}

// -----------------------string-------------------------------------
// char* say = NULL;
// int say_cnt = 0;
// push_char(&say, &say_cnt, 'H');
// push_char(&say, &say_cnt, 'e');
// push_char(&say, &say_cnt, 'l');
// push_char(&say, &say_cnt, 'l');
// push_char(&say, &say_cnt, 'o');
//
// pop_back_char(&say, &say_cnt);
// printf("%d %s\n", say_cnt, say); // 4 Hell
// ------------------------vector of string--------------------------
// #define N 2
// char *arr_str[N];
// int arr_cnt[N] = {0};
// 
// push_char(&arr_str[0], &arr_cnt[0], 'H');
// push_char(&arr_str[0], &arr_cnt[0], 'e');
// push_char(&arr_str[1], &arr_cnt[1], 'l');
// push_char(&arr_str[1], &arr_cnt[1], 'l');
// 
// pop_back_char(&arr_str[1], &arr_cnt[1]);
// 
// printf("%d %s\n", arr_cnt[0], arr_str[0]); // 2 He
// printf("%d %s\n", arr_cnt[1], arr_str[1]); // 1 l
