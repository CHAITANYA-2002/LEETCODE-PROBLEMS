class Solution:
    def multiply(self, num1: str, num2: str) -> str:

        n1 = 0
        n2 = 0

        # num1 ko integer me convert
        for ch in num1:
            n1 = n1 * 10 + (ord(ch) - ord('0'))

        # num2 ko integer me convert
        for ch in num2:
            n2 = n2 * 10 + (ord(ch) - ord('0'))

        return str(n1 * n2)