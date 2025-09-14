#ifndef OFFSETS_H
#define OFFSETS_H

#include "Mem.h"

namespace Offsets {
    //Global
    kaddr GWorld;
    kaddr GNames;
    kaddr GUObjectArray;
    kaddr PointerSize;
    kaddr FUObjectItemSize;

    //---------SDK-----------//
    //---------4.23+---------//
    //Class: FNamePool
    kaddr FNameStride;
    kaddr GNamesToFNamePool;//NamePoolData, alignas(FNamePool)
    kaddr FNamePoolToCurrentBlock;
    kaddr FNamePoolToCurrentByteCursor;
    kaddr FNamePoolToBlocks;
    //Class: FNameEntry
    kaddr FNameEntryToLenBit;
    kaddr FNameEntryToString;
    //Class: UStruct
    kaddr UStructToChildProperties;
    //Class: FField
    kaddr FFieldToClass;
    kaddr FFieldToNext;
    kaddr FFieldToName;
    //---------4.18+---------//
    //Class: FNameEntry
    kaddr FNameEntryToNameString;
    //-----------------------//
    //Class: FUObjectArray
    kaddr FUObjectArrayToTUObjectArray;
    //Class: TUObjectArray
    kaddr TUObjectArrayToNumElements;
    //Class: UObject
    kaddr UObjectToInternalIndex;
    kaddr UObjectToClassPrivate;
    kaddr UObjectToFNameIndex;
    kaddr UObjectToOuterPrivate;
    kaddr UObjectToNamePrivate;
    kaddr UObjectToObjectFlags;
    //Class: UField
    kaddr UFieldToNext;
    kaddr FFieldToFlagsPrivate;
    //Class: UEnum
    kaddr UEnumToNames;
    //Class: UStruct
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    kaddr UStructToPropertiesSize;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToFunc;
    kaddr UFunctionToNumParams;
    kaddr UFunctionToParamSize;
    //Class: FField
    kaddr FFieldToFlagsPrivate;
    //Class: FProperty
    kaddr FPropertyToArrayDim;
    kaddr FPropertyToElementSize;
    kaddr FPropertyToPropertyFlags;
    kaddr FPropertyToOffsetInternal;
    kaddr FPropertyToSize;

    void initOffsets_32() {
        //Global
        PointerSize = 0x4;              
        FUObjectItemSize = 0x18;        // FUObjectItem::Size

        //FName
        UObjectToFNameIndex = 0x4;      // FName::Number

        //FNamePool
        FNameStride = 0x2;              // FNamePool::Stride
        FNamePoolToBlocks = 0xc8;       // FNamePool::BlocksOff
        FNamePoolToCurrentBlock = 0x4;
        FNamePoolToCurrentByteCursor = 0x8;

        //FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;

        //TUObjectArray
        TUObjectArrayToNumElements = 0x4; // TUObjectArray::NumElements

        //UObject
        UObjectToInternalIndex = 0x24;
        UObjectToClassPrivate = 0x8;
        UObjectToOuterPrivate = 0x10;
        UObjectToNamePrivate = 0x1c;
        UObjectToObjectFlags = 0x18;

        //UField
        UFieldToNext = 0x28;

        //UEnum
        UEnumToNames = 0x40;

        //UStruct
        UStructToSuperStruct = 0x40;
        UStructToChildren = 0x50;
        UStructToChildProperties = 0x68;
        UStructToPropertiesSize = 0x3c;

        //UFunction
        UFunctionToFunctionFlags = 0xb8;
        UFunctionToFunc = 0xd8;
        UFunctionToNumParams = 0xb0;
        UFunctionToParamSize = 0xb2;

        //FField
        FFieldToClass = 0x20;
        FFieldToNext = 0x18;
        FFieldToName = 0x28;
        FFieldToFlagsPrivate = 0x8;

        //FProperty
        FPropertyToArrayDim = 0x38;
        FPropertyToElementSize = 0x3c;
        FPropertyToPropertyFlags = 0x40;
        FPropertyToOffsetInternal = 0x4c;
        FPropertyToSize = 0x78;

        //FNameEntry
        FNameEntryToNameString = 0x8;
    }

    void initOffsets_64() {
        //Global
        PointerSize = 0x8;
        FUObjectItemSize = 0x18;       // FUObjectItem::Size

        //FName
        UObjectToFNameIndex = 0x4;     // FName::Number

        //FNamePool
        FNameStride = 0x2;             // FNamePool::Stride
        FNamePoolToBlocks = 0xc8;      // FNamePool::BlocksOff
        FNamePoolToCurrentBlock = 0x8;
        FNamePoolToCurrentByteCursor = 0xc;

        //FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;

        //TUObjectArray
        TUObjectArrayToNumElements = 0x4; // TUObjectArray::NumElements

        //UObject
        UObjectToInternalIndex = 0x24;
        UObjectToClassPrivate = 0x8;
        UObjectToOuterPrivate = 0x10;
        UObjectToNamePrivate = 0x1c;
        UObjectToObjectFlags = 0x18;

        //UField
        UFieldToNext = 0x28;

        //UEnum
        UEnumToNames = 0x40;

        //UStruct
        UStructToSuperStruct = 0x40;
        UStructToChildren = 0x50;
        UStructToChildProperties = 0x68;
        UStructToPropertiesSize = 0x3c;

        //UFunction
        UFunctionToFunctionFlags = 0xb8;
        UFunctionToFunc = 0xd8;
        UFunctionToNumParams = 0xb0;
        UFunctionToParamSize = 0xb2;

        //FField
        FFieldToClass = 0x20;
        FFieldToNext = 0x18;
        FFieldToName = 0x28;
        FFieldToFlagsPrivate = 0x8;

        //FProperty
        FPropertyToArrayDim = 0x38;
        FPropertyToElementSize = 0x3c;
        FPropertyToPropertyFlags = 0x40;
        FPropertyToOffsetInternal = 0x4c;
        FPropertyToSize = 0x78;

        //FNameEntry
        FNameEntryToNameString = 0x10;
    }

    void patchUE423_32() {
        // можно оставить пустым, если не нужны патчи
    }

    void patchUE423_64() {
        // можно оставить пустым, чтобы компилятор не ругался
    }

    void patchCustom_32() {
        // кастомные изменения 32-bit
    }

    void patchCustom_64() {
        // кастомные изменения 64-bit
    }
}

#endif
