#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/Authorization.h"

//begin namespace block
namespace AUTH
{
class ImportAuthorization : public TLBaseObject
{
public:
	ImportAuthorization();
	ImportAuthorization(int32 id, TArray<uint8> bytes);

	~ImportAuthorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

	AUTH::Authorization* GetResult() const
	{
		 return this->result;
	}

private:
	int32 id;
	 TArray<uint8> bytes;
	AUTH::Authorization* result;
};
} //end namespace block
