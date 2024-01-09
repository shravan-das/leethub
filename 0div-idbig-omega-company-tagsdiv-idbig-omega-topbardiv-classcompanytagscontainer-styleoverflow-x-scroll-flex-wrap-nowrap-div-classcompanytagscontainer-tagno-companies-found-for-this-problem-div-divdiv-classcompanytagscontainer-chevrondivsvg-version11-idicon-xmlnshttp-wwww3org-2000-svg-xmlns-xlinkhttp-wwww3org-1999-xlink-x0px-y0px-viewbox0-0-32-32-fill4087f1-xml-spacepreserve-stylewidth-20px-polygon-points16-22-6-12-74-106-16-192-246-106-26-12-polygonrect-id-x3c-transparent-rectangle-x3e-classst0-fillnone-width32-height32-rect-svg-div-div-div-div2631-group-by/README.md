<h2><a href="https://leetcode.com/problems/group-by/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2631. Group By</a></h2><h3>Medium</h3><hr><div><p>Write code that enhances all arrays such that you can call the&nbsp;<code>array.groupBy(fn)</code>&nbsp;method on any array and it will return a <strong>grouped</strong>&nbsp;version of the array.</p>

<p>A&nbsp;<strong>grouped</strong>&nbsp;array is an object where each&nbsp;key&nbsp;is&nbsp;the output of&nbsp;<code>fn(arr[i])</code>&nbsp;and each&nbsp;value is an array containing all items in the original array with that key.</p>

<p>The provided callback&nbsp;<code>fn</code>&nbsp;will accept an item in the array and return a string key.</p>

<p>The order of each value list should be the order the items&nbsp;appear in the array. Any order of keys is acceptable.</p>

<p>Please solve it without lodash's&nbsp;<code>_.groupBy</code> function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
array = [
&nbsp; {"id":"1"},
&nbsp; {"id":"1"},
&nbsp; {"id":"2"}
], 
fn = function (item) { 
&nbsp; return item.id; 
}
<strong>Output:</strong> 
{ 
&nbsp; "1": [{"id": "1"}, {"id": "1"}], &nbsp; 
&nbsp; "2": [{"id": "2"}] 
}
<strong>Explanation:</strong>
Output is from array.groupBy(fn).
The selector function gets the "id" out of each item in the array.
There are two objects with an "id" of 1. Both of those objects are put in the first array.
There is one object with an "id" of 2. That object is put in the second array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> 
array = [
&nbsp; [1, 2, 3],
&nbsp; [1, 3, 5],
&nbsp; [1, 5, 9]
]
fn = function (list) { 
&nbsp; return String(list[0]); 
}
<strong>Output:</strong> 
{ 
&nbsp; "1": [[1, 2, 3], [1, 3, 5], [1, 5, 9]] 
}
<strong>Explanation:</strong>
The array can be of any type. In this case, the selector function defines the key as being the first element in the array. 
All the arrays have 1 as their first element so they are grouped together.
{
  "1": [[1, 2, 3], [1, 3, 5], [1, 5, 9]]
}
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> 
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
fn = function (n) { 
&nbsp; return String(n &gt; 5);
}
<strong>Output:</strong>
{
&nbsp; "true": [6, 7, 8, 9, 10],
&nbsp; "false": [1, 2, 3, 4, 5]
}
<strong>Explanation:</strong>
The selector function splits the array by whether each number is greater than 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= array.length &lt;= 10<sup>5</sup></code></li>
	<li><code>fn</code> returns a string</li>
</ul>
</div>