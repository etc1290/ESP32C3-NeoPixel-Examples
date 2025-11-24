# ESP32C3 x WS2812 NeoPixel 專案

一個展示 ESP32C3 與 WS2812 可尋址 RGB LED (NeoPixel) 互動的 Arduino 專案。包含多個實用範例，從基礎的單個像素控制到互動遊戲應用。

## 📋 專案概述

本專案提供了多個 Arduino 範例，展示如何使用 Adafruit NeoPixel 函式庫控制 WS2812 RGB LED。非常適合作為 Arduino 開發和視覺效果編程的入門教材。

## ⚙️ 硬體需求

- **微控制器**: ESP32-C3 或相容的 Arduino 開發板
- **LED 驅動**: WS2812 可尋址 RGB LED (NeoPixel)
- **腳位連接**: 
  - LED 資料線 → GPIO 3 (預設)
  - 按鈕 (互動範例) → GPIO 4
- **電源**: USB 或外部電源供應

## 📦 軟體需求

### 必需的函式庫
- **Adafruit NeoPixel**: 用於控制 WS2812 LED

在 Arduino IDE 中安裝：
1. 打開 **Sketch → Include Library → Manage Libraries**
2. 搜尋 "Adafruit NeoPixel"
3. 點擊安裝按鈕

## 📚 範例說明

### 1. **Individual Light Up** (`individual_light_up/`)
基礎的個別像素控制範例。

**功能**:
- 依序點亮 LED，展示不同顏色
- 紅色、綠色、藍色、白色輪流顯示
- 每個顏色停留 500 毫秒

**應用場景**: 
- 初學 NeoPixel 基礎
- 測試 LED 硬體連接
- 學習 RGB 色彩組合

**關鍵代碼**:
```cpp
pixels.setPixelColor(position, pixels.Color(Red, Green, Blue));
pixels.show();
```

---

### 2. **Color Blending** (`color_blending/`)
顏色漸層效果範例。

**功能**:
- LED 逐漸從紅色轉變到綠色
- 使用 `map()` 函數實現線性插值
- 每個步驟停留 500 毫秒

**應用場景**:
- 視覺效果設計
- 狀態指示燈
- 資料視覺化

**關鍵代碼**:
```cpp
uint8_t green = map(i, 0, NUMPIXELS - 1, 0, 255);
pixels.setPixelColor(i, pixels.Color(150, green, 0));
```

---

### 3. **Rainbow** (`rainbow/`)
彩虹色循環範例。

**功能**:
- 使用 HSV 色彩空間設定顏色
- 每顆 LED 展示不同的彩虹色調
- 動畫效果展示

**應用場景**:
- 視覺反饋
- 裝飾效果
- 色彩選擇示範

**關鍵代碼**:
```cpp
uint8_t hue = map(i, 0, NUMPIXELS - 1, 0, 65535);
pixels.setPixelColor(i, pixels.ColorHSV(hue));
```

---

### 4. **Ball Game** (`ball/`)
互動式遊戲範例 - 打磚塊遊戲。

**功能**:
- 用按鈕控制球的飛行方向
- 球在 LED 序列中移動
- 綠色部分是目標區域，紅色是遊戲結束
- 當球通過目標時遊戲變快
- 遊戲加速到一定速度即獲勝

**遊戲規則**:
1. 按下按鈕開始遊戲
2. 球向右移動
3. 球抵達最右端時反向
4. 在球回到左側時按按鈕以保持遊戲進行
5. 每次成功增加遊戲難度
6. 加速到 30 毫秒延遲時獲勝

**按鈕設置**: GPIO 4 (INPUT_PULLUP)

**應用場景**:
- 互動遊戲開發
- 狀態管理
- 時間計時與事件處理

**關鍵代碼**:
```cpp
pixels.setPixelColor(position, pixels.Color(127, 127, 0)); // 球
pixels.fill(pixels.Color(0, 127, 0), 0, 3);               // 目標區域
```

---

## 🔧 快速開始

### 步驟 1: 硬體連接
```
ESP32-C3          WS2812 LED Strip
GPIO 3     ----→  DIN (資料輸入)
GND        ----→  GND
5V/3.3V    ----→  5V/3.3V (取決於 LED 電壓)

(按鈕範例需要)
GPIO 4     ←----  按鈕
GND        ←----  按鈕另一端
```

### 步驟 2: 上傳代碼
1. 打開 Arduino IDE
2. 選擇 **Tools → Board → ESP32 → ESP32-C3**
3. 選擇正確的 COM 埠
4. 開啟範例檔案 (`.ino`)
5. 點擊上傳按鈕 (→)

### 步驟 3: 觀察效果
根據選擇的範例，您將看到相應的 LED 效果。

## 🎨 常見自訂設定

### 修改 LED 數量
編輯範例中的定義：
```cpp
#define NUMPIXELS 25  // 改為您的 LED 數量
```

### 修改 GPIO 腳位
```cpp
#define PIN 3  // 改為您的資料線腳位
```

### 調整亮度
在 `setup()` 中添加：
```cpp
pixels.setBrightness(50);  // 0-255，預設最亮
```

### 修改顏色
使用 RGB 值 (0-255)：
```cpp
pixels.setPixelColor(0, pixels.Color(255, 0, 0));     // 紅色
pixels.setPixelColor(0, pixels.Color(0, 255, 0));     // 綠色
pixels.setPixelColor(0, pixels.Color(0, 0, 255));     // 藍色
pixels.setPixelColor(0, pixels.Color(255, 255, 255)); // 白色
```

## 📖 程式設計要點

### 核心函數

| 函數 | 說明 |
|------|------|
| `pixels.begin()` | 初始化 NeoPixel，必須在 setup() 中調用 |
| `pixels.setPixelColor(n, color)` | 設定第 n 顆 LED 的顏色 |
| `pixels.Color(r, g, b)` | 建立 RGB 顏色 (0-255) |
| `pixels.ColorHSV(hue, sat, val)` | 使用 HSV 建立顏色 |
| `pixels.show()` | 將顏色變更更新到 LED |
| `pixels.clear()` | 關閉所有 LED |
| `pixels.fill(color, start, count)` | 填滿指定範圍的 LED |
| `pixels.setBrightness(brightness)` | 設定整體亮度 (0-255) |

### 重要提示
- 每次修改顏色後必須調用 `pixels.show()` 才會生效
- 連續快速改變顏色需要謹慎電源供應
- 大量 LED 同時亮度高時需要外部電源

## 🐛 疑難排解

| 問題 | 解決方案 |
|------|--------|
| LED 不亮 | 檢查 GPIO 腳位設定、USB 連接、LED 供電 |
| 顏色異常 | 檢查 `#define` 中的 LED 協議 (NEO_GRB vs NEO_RGB) |
| 遊戲按鈕無反應 | 確認按鈕連接到正確的 GPIO，檢查 INPUT_PULLUP 設定 |
| 編譯錯誤 | 確認已安裝 Adafruit NeoPixel 函式庫 |

## 📝 授權

本專案中的程式碼基於 Adafruit 提供的範例和 GPL 相容授權。

## 🔗 參考資源

- [Adafruit NeoPixel 文檔](https://github.com/adafruit/Adafruit_NeoPixel)
- [ESP32-C3 規格書](https://www.espressif.com/)
- [Arduino 官方教程](https://www.arduino.cc/)
- [RGB 色彩參考](https://htmlcolorcodes.com/)

---

**最後更新**: 2025 年 11 月 NTU Maker Workshop
