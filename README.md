# Lidar lite Sound

Lidar Lite v3HP で測定した距離値に応じてM5Stackから音を出すことができるプログラム．


## 使用した機材
- Lidar lite v3HP
- M5stack Basic

## ソフトウェア
- Arduino

## ライブラリ
- LIDAR-Lite 2.0.6 （最新バージョン3.0.6だと動作しない）
- M5stack
- ESP32
- I2C

## ツールの調整
- ボード: M5Stack-Core-ESP32
- Upload Speed: "115200"

## フォルダの説明

### frequency
距離値が小さいほど，つまり距離センサと物体の距離が近いほど低周波数の音が鳴る．
※周波数の式は最終的にはint型出力となるが，途中の計算はdouble で行いたいのであえて200.0, 800.0としている．

### volume
距離値が小さいほど，つまり距離センサと物体の距離が近いほど大音量の音が鳴る．

### volume_frequency
Aボタンで周波数，Cボタンでボリュームを変化させるモードに切り替えることができる．アルゴリズムはそれぞれのプログラムと同じ．
