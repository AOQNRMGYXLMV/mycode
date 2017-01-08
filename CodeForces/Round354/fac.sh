#!/bin/bash

factorial()
{
  local i=$1

  if [ $i -eq 0 ]
  then
    return 1;
  else
    factorial `expr $i - 1`
    return `expr $i \* $? `
  fi
}

if [ -z $1 ]
then
  echo "Need one parameter."
  exit 1
fi

factorial $1

echo $?
