#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "html_decode\Header.h"
#include "pch.h"

TEST_CASE("First test")
{
	string htmlString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	string outString = "Cat <says> \" Meow \". M&M’s ";
	CHECK(HtmlDecode(htmlString) == outString);
}