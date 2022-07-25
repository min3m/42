#!/bin/bash
find . | wc -l | awk '{print $1}' 
