<h2><a href="https://leetcode.com/problems/create-hello-world-function/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2667. Create Hello World Function</a></h2><h3>Easy</h3><hr><div>Write a function&nbsp;<code>createHelloWorld</code>.&nbsp;It should return a new function that always returns&nbsp;<code>"Hello World"</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> args = []
<strong>Output:</strong> "Hello World"
<strong>Explanation:</strong>
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> args = [{},null,42]
<strong>Output:</strong> "Hello World"
<strong>Explanation:</strong>
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= args.length &lt;= 10</code></li>
</ul>
</div>