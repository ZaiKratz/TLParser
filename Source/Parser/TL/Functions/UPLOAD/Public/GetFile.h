#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFileLocation.h"
#include "../../../Types/Upload/Public/File.h"

//begin namespace block
namespace UPLOAD
{
class GetFile : public TLBaseObject
{
public:
	GetFile();
	GetFile(COMMON::InputFileLocation* location, int32 offset, int32 limit);

	~GetFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputFileLocation*  Getlocation() const
	{
		 return this->location;
	}

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	UPLOAD::File* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputFileLocation* location;
	 int32 offset;
	 int32 limit;
	UPLOAD::File* result;
};
} //end namespace block
