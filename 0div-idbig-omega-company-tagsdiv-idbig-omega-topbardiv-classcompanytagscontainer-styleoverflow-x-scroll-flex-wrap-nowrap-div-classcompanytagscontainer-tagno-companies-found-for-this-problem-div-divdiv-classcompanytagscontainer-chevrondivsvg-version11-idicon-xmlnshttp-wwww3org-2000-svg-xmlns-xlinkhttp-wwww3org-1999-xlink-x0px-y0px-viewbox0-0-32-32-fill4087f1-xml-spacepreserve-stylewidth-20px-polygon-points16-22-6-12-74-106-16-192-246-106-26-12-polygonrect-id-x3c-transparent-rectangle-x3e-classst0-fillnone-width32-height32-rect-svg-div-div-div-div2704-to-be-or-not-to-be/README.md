<h2><a href="https://leetcode.com/problems/to-be-or-not-to-be/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2704. To Be Or Not To Be</a></h2><h3>Easy</h3><hr><div><p>Write a function&nbsp;<code>expect</code> that helps developers test their code. It should take in any value&nbsp;<code>val</code>&nbsp;and return an object with the following two functions.</p>

<ul>
	<li><code>toBe(val)</code>&nbsp;accepts another value and returns&nbsp;<code>true</code>&nbsp;if the two values&nbsp;<code>===</code>&nbsp;each other. If they are not equal, it should throw an error&nbsp;<code>"Not Equal"</code>.</li>
	<li><code>notToBe(val)</code>&nbsp;accepts another value and returns&nbsp;<code>true</code>&nbsp;if the two values&nbsp;<code>!==</code>&nbsp;each other. If they are equal, it should throw an error&nbsp;<code>"Equal"</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> func = () =&gt; expect(5).toBe(5)
<strong>Output:</strong> {"value": true}
<strong>Explanation:</strong> 5 === 5 so this expression returns true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> func = () =&gt; expect(5).toBe(null)
<strong>Output:</strong> {"error": "Not Equal"}
<strong>Explanation:</strong> 5 !== null so this expression throw the error "Not Equal".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> func = () =&gt; expect(5).notToBe(null)
<strong>Output:</strong> {"value": true}
<strong>Explanation:</strong> 5 !== null so this expression returns true.
</pre>
</div>