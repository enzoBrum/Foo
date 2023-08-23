def main():
    while True:
        h, m = [int(x) for x in input().split(":")]
        if not h and not m:
            break

        # 180 - 90
        # 1 - x



        curr_min = h*60 + m
        curr_min = curr_min
        hour_angle = curr_min*0.5

        min_angle = (m/5)*60
        min_angle = min_angle
        min_angle = min_angle*0.5

        angle = abs(hour_angle-min_angle)

        
        if angle > 180:
            angle = 360 - angle
        print(f"{angle:.3f}")

main()