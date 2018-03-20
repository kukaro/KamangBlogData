#OpenCV
##Mac에서 설치하기
***참고한 사이트***
https://gist.github.com/sigmadream/f1a7778eeaeab79f9888a3292976e438   
***설치 내용***
cd /usr/local/Cellar/opencv  
pkg-config --cflags --libs ./3.4.1_2/lib/pkgconfig/opencv.pc
여기서 버전은 설치된 버전을 한다.  

-I/usr/local/Cellar/opencv/3.4.1_2/include/opencv -I/usr/local/Cellar/opencv/3.4.1_2/include -L/usr/local/Cellar/opencv/3.4.1_2/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_photo -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_face -lopencv_fuzzy -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_ml -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core  

http://webnautes.tistory.com/1036  
캠키는 예제코드  
