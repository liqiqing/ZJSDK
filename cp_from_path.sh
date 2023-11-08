SOURCE_DIR="/Users/mamingkang/ZJSDK_workPace/iOS_ZjSDK_Pro_Optimize"
TARGET_DIR="$(pwd)/ZJSDK"
# if [ -n $1 ]
# then
#     SOURCE_DIR=$1
# fi
echo "输入路径为：$SOURCE_DIR";
echo "目标路径为：$TARGET_DIR";

if [ -d $TARGET_DIR ]
then
    cp -r $SOURCE_DIR/ZJSDK/ZJSDK_Products/ZJSDK.framework                                                   ZJSDK/ZJAdSDK
    cp -r $SOURCE_DIR/ZJSDKCore/ZJSDKCore_Products/ZJSDKCore.framework                                       ZJSDK/ZJAdSDK
    cp -r $SOURCE_DIR/ZJSDKModuleBD/ZJSDKModuleBD_Products/libZJSDKModuleBD.a                                ZJSDK/ZJSDKModuleBD
    cp -r $SOURCE_DIR/ZJSDKModuleCSJ/ZJSDKModuleCSJ_Products/libZJSDKModuleCSJ.a                             ZJSDK/ZJSDKModuleCSJ
    cp -r $SOURCE_DIR/ZJSDKModuleDSP/ZJSDKModuleDSP_Products/libZJSDKModuleDSP.a                             ZJSDK/ZJSDKModuleDSP
    cp -r $SOURCE_DIR/ZJSDKModuleGDT/ZJSDKModuleGDT_Products/libZJSDKModuleGDT.a                             ZJSDK/ZJSDKModuleGDT
    cp -r $SOURCE_DIR/ZJSDKModuleGoogle/ZJSDKModuleGoogle_Products/libZJSDKModuleGoogle.a                    ZJSDK/ZJSDKModuleGoogle
    cp -r $SOURCE_DIR/ZJSDKModuleGoogle/ZJSDKModuleGoogle_Products/ZJSDKModuleGoogle/ZJSDKModuleGoogle.h     ZJSDK/ZJSDKModuleGoogle
    cp -r $SOURCE_DIR/ZJSDKModuleKS/ZJSDKModuleKS_Products/libZJSDKModuleKS.a                                ZJSDK/ZJSDKModuleKS
    cp -r $SOURCE_DIR/ZJSDKModuleMTG/ZJSDKModuleMTG_Products/libZJSDKModuleMTG.a                             ZJSDK/ZJSDKModuleMTG
    cp -r $SOURCE_DIR/ZJSDKModuleSIG/ZJSDKModuleSIG_Products/libZJSDKModuleSIG.a                             ZJSDK/ZJSDKModuleSIG
    cp -r $SOURCE_DIR/ZJSDKModuleYM/ZJSDKModuleYM_Products/libZJSDKModuleYM.a                                ZJSDK/ZJSDKModuleYM
    cp -r $SOURCE_DIR/ZJSDKModuleGromore/ZJSDKModuleGromore_Products/libZJSDKModuleGromore.a                 ZJSDK/ZJSDKModuleGromore
    cp -r $SOURCE_DIR/ZJSDKModuleBeiZi/ZJSDKModuleBeiZi_Products/libZJSDKModuleBeiZi.a                       ZJSDK/ZJSDKModuleBeiZi
    cp -r $SOURCE_DIR/ZJSDKModuleWM/ZJSDKModuleWM_Products/libZJSDKModuleWM.a                                ZJSDK/ZJSDKModuleWM
else
    echo "未检测到有效目标路径，请检查脚本所在目录下是否存在ZJSDK"
fi