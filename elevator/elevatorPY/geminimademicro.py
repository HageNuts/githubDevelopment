from machine import Pin
import utime

class MicroElevator:
    def __init__(self, motor_pin_id):
        # 実際にはモータードライバーなどを制御する想定
        self.motor_pin = Pin(motor_pin_id, Pin.OUT)
        self.current_floor = 1
        self.is_busy = False

    def move(self, target_floor):
        if self.is_busy or target_floor == self.current_floor:
            return
        
        self.is_busy = True
        print("Moving...")
        
        # 移動処理（簡易版）
        diff = abs(target_floor - self.current_floor)
        self.motor_pin.value(1) # モーターON
        utime.sleep_ms(diff * 1000) # 移動時間
        self.motor_pin.value(0) # モーターOFF
        
        self.current_floor = target_floor
        self.is_busy = False
        print("Arrived at floor:", self.current_floor)

class HallPanel:
    """外側のパネル（物理ボタンと連動）"""
    def __init__(self, floor, pin_id):
        self.floor = floor
        self.btn = Pin(pin_id, Pin.IN, Pin.PULL_UP)

    def check(self, elevator):
        # ボタンが押されたかチェック(0=押された)
        if self.btn.value() == 0:
            print(f"External call from floor {self.floor}")
            elevator.move(self.floor)

# --- 実行イメージ ---
# elevator = MicroElevator(motor_pin_id=2)
# f1_button = HallPanel(floor=1, pin_id=14)

# while True:
#     f1_button.check(elevator)
#     utime.sleep_ms(100)