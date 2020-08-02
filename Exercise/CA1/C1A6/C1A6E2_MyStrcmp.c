//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A6E2_MyStrcmp.c
// Win10
// Visual C++ 19.0
//
// This function compare the contents of two strings identified to the pointers
// passed by the user
// Will return:  < 0  when s1 < s2
//                 0  when s1 = s2
//               > 0  when s1 > s2
//

int MyStrcmp(const char *s1, const char *s2)
{
   // Increment pointers until the s1 does not equal s2
   // AND ensure we do not increment past null character '\0'
   while (*s1 == *s2 && *s1 != '\0')
   {
      ++s1;
      ++s2;
   }

   return (int)(*s1 - *s2);
}
