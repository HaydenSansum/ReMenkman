#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    srcImg.load("outdoors.jpg");
    impImg.load("indoor.jpg");
    srcImg.setImageType(OF_IMAGE_COLOR);
    srcImg.resize(ofGetWidth(), ofGetHeight());
    impImg.setImageType(OF_IMAGE_COLOR);
    impImg.resize(ofGetWidth(), ofGetHeight());
    
    swap_num = 0;
    mod_num = 500000;
    switch_trigger = false;
    
    ofBuffer test_bf;
    ofSaveImage(srcImg.getPixels(), test_bf, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
    
    // Create a vector the size of the image buffer
    for (int j = 10000; j < test_bf.size(); j++) {
        all_buf_vals.push_back(j);
    }

    // Shuffle this vector
    random_shuffle(all_buf_vals.begin(), all_buf_vals.end());
    
}


//--------------------------------------------------------------
void ofApp::update(){
     
    swap_num += 1000;
   
    if (switch_trigger) {
        mod_num = 1 + ((mod_num - 1)* 0.95);
    } else {
        mod_num -= 2000;
    }
    if (mod_num < 1) {
        mod_num = 1.001;
        switch_trigger = true;
    }
    
    ofBuffer src_bf;
    ofSaveImage(srcImg.getPixels(), src_bf, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
    ofBuffer imp_bf;
    ofSaveImage(impImg.getPixels(), imp_bf, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
    ofBuffer out_bf;
    
//    swap_array.clear();
//    for (int k = 0; k < swap_num; k++) {
//        swap_array.push_back(all_buf_vals[k]);
//    }
    
    
        
    int size = src_bf.size();
    for (int i = 0; i < size; i++) {
//        if (i > size - (swap_num + 80000) || i < 5000 + (swap_num/6)) {
//        if (switch_trigger) {
//            if (i < 100) {
//                cout << "modnum: " << mod_num << endl;
//                cout << "i: " << i << endl;
//                cout << (int) fmod(i, mod_num) << endl;
//            }
//            if ((int) fmod(i, mod_num) == 0) {
//                char * data = src_bf.getData()+i;
//                out_bf.append(data, 1);
//            } else {
//                out_bf.append(imp_bf.getData() + i, 1);
//            }
//        } else {
            if ((int) fmod(i, mod_num) == 0) {
                char * data = imp_bf.getData()+i;
                out_bf.append(data, 1);
            } else {
                out_bf.append(src_bf.getData() + i, 1);
            }
        }
       
//    }
    outImg.load(out_bf);
    
    
//    char * data = new char[1];
//    data[0] = ofRandom(0,255);
//    bf2.append(data, 1);
//    delete data;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    outImg.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        screen_grab.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screen_grab.save(ofGetTimestampString() + "screenshot.png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
