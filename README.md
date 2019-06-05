# RFID 实验

- ## 连线说明

1. 彩灯


> 传感器引脚        板子引脚
>
> rgb_GND   ---     GND
>
> rgb_b     ---     2
>
> rgb_g     ---     5
>
> rgb_g     ---     6
>
---
2. 温湿度

> 传感器引脚       板子引脚
>
> GND       ----    GND
>
> VCC       ---     VCC
>
> S         ---     A0
>
____

3. LCD显示屏

> 传感器引脚       板子引脚
>
> GND       ----    GND
>
> VCC       ---     VCC
>
> S         ---     A0
>
----

4. RFID-RC522 模块

> 传感器引脚       板子引脚
>
> GND       ----    GND
>
> VCC       ---     VCC
>
> S         ---     A0
>
----

5. 红外接收器

> 传感器引脚       板子引脚
>
> GND       ----    GND
>
> VCC       ---     VCC
>
> S         ---     A0
>
----

6. 其他模块


- ## 使用说明

### 模式说明

- `RFID read card`

    RFID读卡 UID
- `RFID led`

    RFID控制灯
- `Te,hu monitor`

    温湿度监控
- `rgb led`

    彩灯控制

### 主页

显示效果
```txt
input key -pd+pu
0:RFID read card
```
使用说明
> 按键  说明
>
> `0` 进入模式0 (`RFID read card`)
>
> `1` 入模式1 (`RFID led`)
>
> `2` 进入模式2 (`Te,hu monitor`)
>
> `3` 进入模式3 (`rgb led`)
>
> `-` 向下翻页
>
> `+` 向上翻页
>


### 0. `read card`(RFID读卡)

>
>
>
>
>
>
>
----

### 1. `RFID led`(RFID控制灯))
---

### 2. `Te,hu monitor`(温湿度监控)

---
### 3. `rgb led`(彩灯模式)






















