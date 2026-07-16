import time

class Elevator:
    def __init__(self, name, top_floor=5):
        self.name = name
        self.current_floor = 1
        self.top_floor = top_floor
        self.door_open = False

    def move_to(self, target_floor):
        if target_floor == self.current_floor:
            self.open_door()
            return

        print(f"\n[{self.name}] {self.current_floor}階から{target_floor}階へ移動中...")
        self.close_door()
        
        while self.current_floor != target_floor:
            step = 1 if target_floor > self.current_floor else -1
            time.sleep(0.5)  # 移動の演出
            self.current_floor += step
            print(f"現在: {self.current_floor}階")
            
        self.open_door()

    def open_door(self):
        if not self.door_open:
            print(f"[{self.name}] 扉が開きます。")
            self.door_open = True

    def close_door(self):
        if self.door_open:
            print(f"[{self.name}] 扉が閉まります。")
            self.door_open = False

class ExternalButton:
    """各階の外側にあるボタン"""
    def __init__(self, floor):
        self.floor = floor

    def call(self, elevator_instance, direction):
        print(f"\n--- {self.floor}階で【{direction}】ボタンが押されました ---")
        elevator_instance.move_to(self.floor)

# --- 実行セクション ---
# インスタンス化
my_elevator = Elevator("メイン機", top_floor=10)
floor_3_btn = ExternalButton(3)

# 外側のボタンから呼び出し（参照渡し：エレベーター本体を渡す）
floor_3_btn.call(my_elevator, "上")

# エレベーター内側での操作を想定
print("\n[内側操作] 5階のボタンが押されました。")
my_elevator.move_to(5)