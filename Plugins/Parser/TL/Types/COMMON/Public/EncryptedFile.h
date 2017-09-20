#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class EncryptedFile : public TLBaseObject
{
public:
	EncryptedFile();
	EncryptedFile(unsigned long long id, unsigned long long access_hash, int32 size, int32 dc_id, int32 key_fingerprint);

	~EncryptedFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
	 int32 size;
	 int32 dc_id;
	 int32 key_fingerprint;
};
} //end namespace block
