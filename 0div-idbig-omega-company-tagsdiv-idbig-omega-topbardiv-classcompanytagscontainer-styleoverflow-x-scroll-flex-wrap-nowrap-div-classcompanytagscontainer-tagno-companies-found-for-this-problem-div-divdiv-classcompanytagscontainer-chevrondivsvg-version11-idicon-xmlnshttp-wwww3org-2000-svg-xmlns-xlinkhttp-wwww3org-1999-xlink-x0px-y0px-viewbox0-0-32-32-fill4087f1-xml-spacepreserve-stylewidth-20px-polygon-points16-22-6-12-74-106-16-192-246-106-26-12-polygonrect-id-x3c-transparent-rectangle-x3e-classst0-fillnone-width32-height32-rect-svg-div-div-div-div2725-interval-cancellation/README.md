<h2><a href="https://leetcode.com/problems/interval-cancellation/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2725. Interval Cancellation</a></h2><h3>Easy</h3><hr><div><p>Given a function <code>fn</code>, an array of arguments&nbsp;<code>args</code>, and&nbsp;an interval time <code>t</code>, return a cancel function <code>cancelFn</code>.</p>

<p>The function <code>fn</code> should be called with <code>args</code> immediately and then called again every&nbsp;<code>t</code> milliseconds&nbsp;until&nbsp;<code>cancelFn</code>&nbsp;is called at <code>cancelTimeMs</code> ms.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> fn = (x) =&gt; x * 2, args = [4], t = 35
<strong>Output:</strong> 
[
   {"time": 0, "returned": 8},
   {"time": 35, "returned": 8},
   {"time": 70, "returned": 8},
   {"time": 105, "returned": 8},
   {"time": 140, "returned": 8},
   {"time": 175, "returned": 8}
]
<strong>Explanation:</strong> 
const cancelTimeMs = 190;
const cancelFn = cancellable((x) =&gt; x * 2, [4], 35);
setTimeout(cancelFn, cancelTimeMs);

Every 35ms, fn(4) is called. Until t=190ms, then it is cancelled.
1st fn call is at 0ms. fn(4) returns 8.
2nd fn call is at 35ms. fn(4) returns 8.
3rd fn call is at 70ms. fn(4) returns 8.
4th fn call is at&nbsp;105ms. fn(4) returns 8.
5th fn call is at 140ms. fn(4) returns 8.
6th fn call is at 175ms. fn(4) returns 8.
Cancelled at 190ms
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> fn = (x1, x2) =&gt; (x1 * x2), args = [2, 5], t = 30
<strong>Output:</strong> 
[
   {"time": 0, "returned": 10},
   {"time": 30, "returned": 10},
   {"time": 60, "returned": 10},
   {"time": 90, "returned": 10},
   {"time": 120, "returned": 10},
   {"time": 150, "returned": 10}
]
<strong>Explanation:</strong> 
const cancelTimeMs = 165; 
const cancelFn = cancellable((x1, x2) =&gt; (x1 * x2), [2, 5], 30) 
setTimeout(cancelFn, cancelTimeMs)

Every 30ms, fn(2, 5) is called. Until t=165ms, then it is cancelled.
1st fn call is at 0ms&nbsp;
2nd fn call is at 30ms&nbsp;
3rd fn call is at 60ms&nbsp;
4th fn call is at&nbsp;90ms&nbsp;
5th fn call is at 120ms&nbsp;
6th fn call is at 150ms
Cancelled at 165ms
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> fn = (x1, x2, x3) =&gt; (x1 + x2 + x3), args = [5, 1, 3], t = 50
<strong>Output:</strong> 
[
   {"time": 0, "returned": 9},
   {"time": 50, "returned": 9},
   {"time": 100, "returned": 9},
   {"time": 150, "returned": 9}
]
<strong>Explanation:</strong> 
const cancelTimeMs = 180;
const cancelFn = cancellable((x1, x2, x3) =&gt; (x1 + x2 + x3), [5, 1, 3], 50)
setTimeout(cancelFn, cancelTimeMs)

Every 50ms, fn(5, 1, 3) is called. Until t=180ms, then it is cancelled. 
1st fn call is at 0ms
2nd fn call is at 50ms
3rd fn call is at 100ms
4th fn call is at&nbsp;150ms
Cancelled at 180ms
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>fn</code> is a function</li>
	<li><code>args</code> is a valid JSON array</li>
	<li><code>1 &lt;= args.length &lt;= 10</code></li>
	<li><code><font face="monospace">30 &lt;= t &lt;= 100</font></code></li>
	<li><code><font face="monospace">10 &lt;= </font>cancelTimeMs<font face="monospace"> &lt;= 500</font></code></li>
</ul>
</div>