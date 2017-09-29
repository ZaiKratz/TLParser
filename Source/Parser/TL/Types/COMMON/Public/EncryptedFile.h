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

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	int32 Getsize() const
	{
		 return this->size;
	}

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	int32 GetKeyFingerprint() const
	{
		 return this->key_fingerprint;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
	 int32 size;
	 int32 dc_id;
	 int32 key_fingerprint;
};
} //end namespace block
