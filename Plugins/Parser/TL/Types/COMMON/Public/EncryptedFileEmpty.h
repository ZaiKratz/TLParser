#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedFile.h"

//begin namespace block
namespace COMMON
{
class EncryptedFileEmpty : public TLBaseObject
{
public:
	EncryptedFileEmpty();
	~EncryptedFileEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
