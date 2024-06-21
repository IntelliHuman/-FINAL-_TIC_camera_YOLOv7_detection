import os

# 데이터셋 라벨이 저장된 폴더 경로를 지정하세요.
label_dir = '/home/smu_user/yolov7_add_rfb/temp2/custom_dataset/labels/test'

def fix_labels(directory):
    # 디렉토리 내 모든 파일을 검사합니다.
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):  # 라벨 파일 확인
            filepath = os.path.join(directory, filename)
            with open(filepath, 'r') as file:
                lines = file.readlines()
            
            # 각 라인을 수정할 필요가 있는지 확인합니다.
            corrected_lines = []
            need_correction = False
            for line in lines:
                parts = line.strip().split()
                class_index = int(parts[0])
                if class_index == 1:  # 잘못된 클래스 인덱스를 찾았을 경우
                    parts[0] = '0'  # 0으로 수정
                    need_correction = True
                corrected_lines.append(' '.join(parts))
            
            # 파일에 수정된 내용을 다시 쓰기
            if need_correction:
                with open(filepath, 'w') as file:
                    file.write('\n'.join(corrected_lines) + '\n')
                print(f"Corrected {filename}")

# 함수를 호출하여 라벨 파일들을 수정합니다.
fix_labels(label_dir)
