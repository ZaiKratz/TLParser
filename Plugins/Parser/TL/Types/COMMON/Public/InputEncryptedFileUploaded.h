#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedFile.h"

//begin namespace block
namespace COMMON
{
class InputEncryptedFileUploaded : public TLBaseObject
{
public:
	InputEncryptedFileUploaded();
	InputEncryptedFileUploaded(unsigned long long id, int32 parts, FString md5_checksum, int32 key_fingerprint);

	~InputEncryptedFileUploaded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 int32 parts;
	 FString md5_checksum;
	 int32 key_fingerprint;
};
} //end namespace block
