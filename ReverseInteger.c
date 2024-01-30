def reverse(x):
    INT_MAX = 2**31 - 1
    INT_MIN = -2**31
    
    sign = 1 if x > 0 else -1
    x = abs(x)
    
    reversed_x = 0
    while x != 0:
    {
        digit = x % 10
        x //= 10
        
        if reversed_x > (INT_MAX - digit) // 10:
        {
            return 0;
        } 
        reversed_x = reversed_x * 10 + digit
    }
    return sign * reversed_x

print(reverse(123))   # Output: 321
print(reverse(-123))  # Output: -321
print(reverse(120))   # Output: 21
