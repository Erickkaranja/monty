#!/usr/bin/env python3
'''pagination implemention in python.'''
from typing import Tuple


def index_range(page: int, page_size: int) -> Tuple[int, int]:
    '''simple pagination implemention function.'''
    start_index: int = page_size * page - page_size
    end_index: int = page_size * page
    return (start_index, end_index)
