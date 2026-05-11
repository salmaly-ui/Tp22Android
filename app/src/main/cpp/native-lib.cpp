#include <jni.h>
#include <string>
#include <algorithm>
#include <android/log.h>

#define LOG_TAG "NATIVE"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_example_jnibridge_MainActivity_getWelcomeMessage(
        JNIEnv* env,
        jobject /* this */) {

    LOGI("getWelcomeMessage called from Java");
    return env->NewStringUTF("Welcome to JNI Bridge!");
}

JNIEXPORT jint JNICALL
Java_com_example_jnibridge_MainActivity_calculateProduct(
        JNIEnv* env,
        jobject /* this */,
        jint a,
        jint b) {

    LOGI("Calculating product: %d x %d", a, b);
    return a * b;
}

JNIEXPORT jstring JNICALL
Java_com_example_jnibridge_MainActivity_transformText(
        JNIEnv* env,
        jobject /* this */,
        jstring input) {

    const char* source = env->GetStringUTFChars(input, nullptr);
    std::string text(source);
    env->ReleaseStringUTFChars(input, source);

    // Transformer: inverser la casse
    for (char &c : text) {
        if (c >= 'a' && c <= 'z') {
            c = c - 32;  // majuscule
        } else if (c >= 'A' && c <= 'Z') {
            c = c + 32;  // minuscule
        }
    }

    // Inverser la chaine
    std::reverse(text.begin(), text.end());

    LOGI("Transformed text: %s", text.c_str());
    return env->NewStringUTF(text.c_str());
}

JNIEXPORT jint JNICALL
Java_com_example_jnibridge_MainActivity_sumIntegerArray(
        JNIEnv* env,
        jobject /* this */,
        jintArray array) {

    jsize length = env->GetArrayLength(array);
    jint* elements = env->GetIntArrayElements(array, nullptr);

    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += elements[i];
    }

    env->ReleaseIntArrayElements(array, elements, JNI_ABORT);

    LOGI("Sum of array: %d", sum);
    return sum;
}

}