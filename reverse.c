/** Program to demonstrate string reversal
 */

#include <stdio.h>
#include <string.h>
#include <libgen.h>

/** Print usage message
 */
void usage () {
  printf("usage: reversestring \"string with characters to reverse\"\n");
  printf("   OR: reversewords \"string with words to reverse\"\n");
}

/** Reverses all the characters in a string, in place.
 * For example, "hello world" becomes "dlrow olleh"
 */

void reverseOneWord(char*s, int start, int end){
	while(start < end){
	     char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}
		
void reversestring(char* s) {
	int l;
	int i;
	l = strlen(s);

	for(i = 0; i < l/2; i++){
		char temp;
		temp = s[i];
		s[i] = s[l - 1 - i];
		s[l -1 - i] = temp;
	}		
}

/** Reverses all the words in a string, in place.
 * For example, "hello world" becomes "world hello"
 */
void reversewords(char* s) {
	int i = 0;
	int l = strlen(s);
	reversestring(s);
	int start = 0;
	int end;
	for(i = 0; i < l; i++){
		if(s[i] == ' '){
			end = i -1;
			reverseOneWord(s,start,end);
			start = i+1;
		}
	}
	reverseOneWord(s,start,l-1);
}

/** Must take exactly one argument.
 */
int main(int argc, char* argv[]) {

  char* command; // duplicate of command name
  char* basec;    // basename of command
  char* s;       // String to reverse;

  if (argc != 2) { // Check that it was called with exactly one argument
    usage();
    return 1;
  }

  s = strdup(argv[1]); // Sring to reverse

  // See how the command was invoked

  // First strip down to just the basename, no directory prefix
  command = strdup(argv[0]);
  basec = basename(command);

  if (strcmp(basec, "reversestring") == 0) {
    printf("Original string: %s\n", s);
    reversestring(s);
    printf("Reversed string: %s\n", s);
    return 0;
  } else if (strcmp(basec, "reversewords") == 0) {
    printf("Original string: %s\n", s);
    reversewords(s);
    printf("Reversed string: %s\n", s);
    return 0;
  } else { // Those are the only two valid choices
    usage();
    return 1;
  }
}
