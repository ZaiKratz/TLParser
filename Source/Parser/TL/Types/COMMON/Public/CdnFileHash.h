#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class CdnFileHash : public TLBaseObject
{
public:
	CdnFileHash();
	CdnFileHash(int32 offset, int32 limit, TArray<uint8> hash);

	~CdnFileHash();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	TArray<uint8>  Gethash() const
	{
		 return this->hash;
	}

private:
	int32 offset;
	 int32 limit;
	 TArray<uint8> hash;
};
} //end namespace block
