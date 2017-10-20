#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeFilename : public TLBaseObject
{
public:
	DocumentAttributeFilename();
	DocumentAttributeFilename(FString file_name);

	~DocumentAttributeFilename();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetFileName() const
	{
		 return this->file_name;
	}

private:
	FString file_name;
};
} //end namespace block
