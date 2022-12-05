# CPS511-A3 - Ramneek Riar

Uses glut to compile the program. I used Xcode as my IDE on macOS, so I added the approporiate #include statements dependent on if the program is being ran on a windows or mac environment.

```g++ main.cpp robot.cpp player.cpp laser.cpp -o A3.out -framework OpenGL -framework GLUT```
```./A3.out```

Requirements met:
- 3 robots walking (with animation) along the ground towards cannon
- 3 robots fire lasers
- Defensive cannon is texture mapped
- Defensive cannon fires laser using Spacebar
- Lasers are animated (both for robot and cannon)
- Defensive cannon is mouse-controlled
- Defensive cannon built using custom mesh
- Bonus -> Defensive cannon fires laser instead of projectile
