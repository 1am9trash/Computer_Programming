# Master Theorem

#### 快速估算遞迴演算法複雜度的公式。

$$
if\ T (n) = aT(\left \lceil \frac{n}{b}\right \rceil) + O(n^d)\ (for\ constants\ a > 0,\ b > 1,\ d \geq 0)\\
T(n) = 
\left\{\begin{matrix}
&O(n^d) &{if\ d > log_{b}\ a} &\\ 
&O(n^d\ log\ n) &{if\ d = log_{b}\ a}\\
&O(n^{log_b\ a}) &{if\ d < log_{b}\ a}
\end{matrix}\right. 
$$
