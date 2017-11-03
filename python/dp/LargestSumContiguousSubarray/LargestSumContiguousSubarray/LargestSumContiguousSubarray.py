'''
#Kadane’s Algorithm:

#Initialize:
#    max_so_far = 0
#    max_ending_here = 0

#Loop for each element of the array
#  (a) max_ending_here = max_ending_here + a[i]
#  (b) if(max_ending_here < 0)
#            max_ending_here = 0
#  (c) if(max_so_far < max_ending_here)
#            max_so_far = max_ending_here
#return max_so_far
'''

def maxSubArraySum(a,len):
    sum_so_far = 0
    sum_ending_here = 0
    for i in a:
        sum_ending_here += i
        if(sum_ending_here < 0):
            sum_ending_here = 0
        if(sum_so_far < sum_ending_here):
            sum_so_far  = sum_ending_here
    return sum_so_far


if __name__ == '__main__':
    a = [-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]
    b = [-2,-3,4,-1,-2,1,5,3]
    print ("Maximum contiguous sum is ", maxSubArraySum(a,len(a)))
    print ("Maximum contiguous sum is ", maxSubArraySum(b,len(b)))


