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
    //Class: UField
    kaddr UFieldToNext;
    //Class: UStruct
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToFunc;
    //Class: UProperty
    kaddr UPropertyToElementSize;
    kaddr UPropertyToPropertyFlags;
    kaddr UPropertyToOffsetInternal;
    //Class: UBoolProperty
    kaddr UBoolPropertyToFieldSize;
    kaddr UBoolPropertyToByteOffset;
    kaddr UBoolPropertyToByteMask;
    kaddr UBoolPropertyToFieldMask;
    //Class: UObjectProperty
    kaddr UObjectPropertyToPropertyClass;
    //Class: UClassProperty
    kaddr UClassPropertyToMetaClass;
    //Class: UInterfaceProperty
    kaddr UInterfacePropertyToInterfaceClass;
    //Class: UArrayProperty
    kaddr UArrayPropertyToInnerProperty;
    //Class: UMapProperty
    kaddr UMapPropertyToKeyProp;
    kaddr UMapPropertyToValueProp;
    //Class: USetProperty
    kaddr USetPropertyToElementProp;
    //Class: UStructProperty
    kaddr UStructPropertyToStruct;
    //Class: UWorld
    kaddr UWorldToPersistentLevel;
    //Class: ULevel
    kaddr ULevelToAActors;
    kaddr ULevelToAActorsCount;

    void initOffsets_32() {
        //Global
        PointerSize = 0x4;               // оставлено
        FUObjectItemSize = 0x18;         // заменено на FUObjectItem::Size

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x8;    // оставлено

        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10; // оставлено

        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x4;    // заменено на TUObjectArray::NumElements

        //Class: UObject
        UObjectToInternalIndex = 0x24;       // заменено на UObject::InternalIndex
        UObjectToClassPrivate = 0x8;         // заменено на UObject::ClassPrivate
        UObjectToFNameIndex = 0x4;           // заменено на FName::Number
        UObjectToOuterPrivate = 0x10;        // заменено на UObject::OuterPrivate

        //Class: UField
        UFieldToNext = 0x28;                 // заменено на UField::Next

        //Class: UStruct
        UStructToSuperStruct = 0x40;         // заменено на UStruct::SuperStruct
        UStructToChildren = 0x50;            // заменено на UStruct::Children
        UStructToChildProperties = 0x68;     // заменено на UStruct::ChildProperties

        //Class: UFunction
        UFunctionToFunctionFlags = 0xb8;     // заменено на UFunction::EFunctionFlags
        UFunctionToFunc = 0xd8;              // заменено на UFunction::Func

        //Class: UProperty
        UPropertyToElementSize = 0x3c;       // заменено на FProperty::ElementSize
        UPropertyToPropertyFlags = 0x40;     // заменено на FProperty::PropertyFlags
        UPropertyToOffsetInternal = 0x4c;    // заменено на FProperty::Offset_Internal

        //Class: FField
        FFieldToClass = 0x20;                // заменено на FField::ClassPrivate
        FFieldToNext = 0x18;                 // заменено на FField::Next
        FFieldToName = 0x28;                 // заменено на FField::NamePrivate

        //FNamePool
        FNameStride = 2;                      // заменено на FNamePool::Stride
        FNamePoolToBlocks = 0xc8;            // заменено на FNamePool::BlocksOff
        FNamePoolToCurrentBlock = 0x4;       // оставлено
        FNamePoolToCurrentByteCursor = 0x8;  // оставлено

        //Дополнительно
        UObjectToNamePrivate = 0x1c;         // заменено на UObject::NamePrivate
        UObjectToObjectFlags = 0x18;         // заменено на UObject::ObjectFlags
        UEnumToNames = 0x40;                 // заменено на UEnum::Names
        UStructToPropertiesSize = 0x3c;      // заменено на UStruct::PropertiesSize
        UFunctionToNumParams = 0xb0;         // заменено на UFunction::NumParams
        UFunctionToParamSize = 0xb2;         // заменено на UFunction::ParamSize
        FFieldToFlagsPrivate = 0x8;          // заменено на FField::FlagsPrivate
        FPropertyToArrayDim = 0x38;          // заменено на FProperty::ArrayDim
        FPropertyToSize = 0x78;              // заменено на FProperty::Size
    }

    void initOffsets_64() {
        //Global
        PointerSize = 0x8;                   // оставлено
        FUObjectItemSize = 0x18;             // заменено на FUObjectItem::Size

        //Class: FNameEntry
        FNameEntryToNameString = 0x10;       // оставлено

        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10; // оставлено

        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x4;    // заменено на TUObjectArray::NumElements

        //Class: UObject
        UObjectToInternalIndex = 0x24;       // заменено на UObject::InternalIndex
        UObjectToClassPrivate = 0x8;         // заменено на UObject::ClassPrivate
        UObjectToFNameIndex = 0x4;           // заменено на FName::Number
        UObjectToOuterPrivate = 0x10;        // заменено на UObject::OuterPrivate

        //Class: UField
        UFieldToNext = 0x28;                 // заменено на UField::Next

        //Class: UStruct
        UStructToSuperStruct = 0x40;         // заменено на UStruct::SuperStruct
        UStructToChildren = 0x50;            // заменено на UStruct::Children
        UStructToChildProperties = 0x68;     // заменено на UStruct::ChildProperties

        //Class: UFunction
        UFunctionToFunctionFlags = 0xb8;     // заменено на UFunction::EFunctionFlags
        UFunctionToFunc = 0xd8;              // заменено на UFunction::Func

        //Class: UProperty
        UPropertyToElementSize = 0x3c;       // заменено на FProperty::ElementSize
        UPropertyToPropertyFlags = 0x40;     // заменено на FProperty::PropertyFlags
        UPropertyToOffsetInternal = 0x4c;    // заменено на FProperty::Offset_Internal

        //Class: FField
        FFieldToClass = 0x20;                // заменено на FField::ClassPrivate
        FFieldToNext = 0x18;                 // заменено на FField::Next
        FFieldToName = 0x28;                 // заменено на FField::NamePrivate

        //FNamePool
        FNameStride = 2;                      // заменено на FNamePool::Stride
        FNamePoolToBlocks = 0xc8;            // заменено на FNamePool::BlocksOff
        FNamePoolToCurrentBlock = 0x8;       // оставлено
        FNamePoolToCurrentByteCursor = 0xc;  // оставлено

        //Дополнительно
        UObjectToNamePrivate = 0x1c;         // заменено на UObject::NamePrivate
        UObjectToObjectFlags = 0x18;         // заменено на UObject::ObjectFlags
        UEnumToNames = 0x40;                 // заменено на UEnum::Names
        UStructToPropertiesSize = 0x3c;      // заменено на UStruct::PropertiesSize
        UFunctionToNumParams = 0xb0;         // заменено на UFunction::NumParams
        UFunctionToParamSize = 0xb2;         // заменено на UFunction::ParamSize
        FFieldToFlagsPrivate = 0x8;          // заменено на FField::FlagsPrivate
        FPropertyToArrayDim = 0x38;          // заменено на FProperty::ArrayDim
        FPropertyToSize = 0x78;              // заменено на FProperty::Size
    }
}

#endif
